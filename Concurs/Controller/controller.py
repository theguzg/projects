'''
Created on Dec 1, 2016

@author: Gutza
'''

from Domain.entities import Participant
from Repository.inmemory import InMemoryRepository
from Repository.inmemory import RepositoryException
from Domain.validators import ParticipantValidator
import copy

class ParticipantController :
    def __init__(self,rep,val):
        """
        Initializeaza controllerul :
        rep = obiect pentru a retine participantii
        val = obiect pentru a valida participantii
        """
        self.rep = rep
        self.__val = val
        self.backup=[]
    def reg(self):
        self.backup.append(copy.deepcopy(self.rep.allpart))
        if len(self.backup) > 10:
            self.backup.pop(0)
    def und(self):
        
        if (len(self.backup)>1):
            poz=len(self.backup)-2
            self.rep.allpart=[]
            self.rep.allpart=copy.deepcopy(self.backup[poz])
            self.backup.pop(poz+1)


        
    def CreateParticipant(self,idconc,nume,score):
        
        conc = Participant(idconc,nume,score)
        
        self.__val.validate(conc)
        
        self.rep.Store(conc)
        self.reg()

        
        return conc
    
    def RemoveScore(self,idpart):
        """
        Sterge scorul unui participant cu id-ul dat.
        """
        for i in range(0,len(self.rep.allpart)):
            if self.rep.allpart[i].GetId() == idpart:
                self.rep.allpart[i].SetScore(0)
        self.reg()
    def RemoveScoreInterval(self,limita_stanga,limita_dreapta):
        """
        Sterge scorul mai multor participanti dintr-un interval dat
        """
        
        for i in range(0,len(self.rep.allpart)):
            if self.rep.allpart[i].GetId() >= limita_stanga and self.rep.allpart[i].GetId() <= limita_dreapta:
                self.rep.allpart[i].SetScore(0)
        self.reg()        
    def ModifyScore(self,idpart,score):
        """
        Modifica scorul unui participant cu un id dat
        """
        for i in range(0,len(self.rep.allpart)):
            if self.rep.allpart[i].GetId() == idpart:
                self.rep.allpart[i].SetScore(score)
        self.reg()       
    def FilterByMultiplier(self,number):
        """
        Sterge toti participantii care nu sunt divizibili cu un numar dat
        """
        for participant in self.rep.allpart:
            if participant.GetScore() % number == 0:
                self.rep.Delete(participant)                
        self.reg()
    def FilterByLower(self,number):
        """
        Sterge toti participantii care au scorul mai mic decat un numar dat
        """
        for participant in self.rep.allpart:
            if participant.GetScore() < number :
                self.rep.Delete(participant)
        self.reg()        
    def MediaForInterval(self,limita_stanga,limita_dreapta):
        """
        Face media aritmetica a scorurilor unor participanti pentru un interval dat de participanti
        """
        suma = 0
        for i in range(0,len(self.rep.allpart)):
            if self.rep.allpart[i].GetId() >= limita_stanga and self.rep.allpart[i].GetId() <= limita_dreapta:
                suma = suma + self.rep.allpart[i].GetScore()
        
        return float(suma / limita_dreapta - limita_stanga + 1)
    
    def ScoreMinimumForInterval(self,limita_stanga,limita_dreapta):
        """
        Calculeaza cel mai mic scor al unui participant pentru un interval dat de participanti
        """
        lista_auxiliara = []
        for i in range(0,len(self.rep.allpart)):
            if self.rep.allpart[i].GetId() >= limita_stanga and self.rep.allpart[i].GetId() <= limita_dreapta:
                lista_auxiliara.append(self.rep.allpart[i].GetScore())
        
        return min(lista_auxiliara)
           
        
    def GetAllParticipants(self):
        
        return self.rep.GetAllParticipants()
    
def TestCreateParticipant():
    rep = InMemoryRepository()
    val = ParticipantValidator()
    ctr = ParticipantController(rep,val)
    conc = ctr.CreateParticipant(1, "Ion", 92)
    assert conc.GetId() == 1
    assert conc.GetNume() == "Ion"
    assert conc.GetScore() == 92
    allpart = ctr.GetAllParticipants()
    assert len(allpart) == 1
    assert allpart[0] == conc
    
    try :
        conc = ctr.CreateParticipant(1,"Marcel",55)
        assert True
    except RepositoryException :
        assert False
        
def TestRemoveScore():
    rep = InMemoryRepository()
    val = ParticipantValidator()
    ctr = ParticipantController(rep,val)
    conc = ctr.CreateParticipant(1, "Ion", 55)
    
    
    assert conc.GetScore() == 55
    ctr.RemoveScore(1)
    assert conc.GetScore() == 0

def TestModifyScore():
    rep = InMemoryRepository()
    val = ParticipantValidator()
    ctr = ParticipantController(rep,val)
    conc = ctr.CreateParticipant(1,"Vasile",20)
    
    assert conc.GetScore() == 20
    ctr.ModifyScore(1, 69)
    assert conc.GetScore() == 69
    
def TestRemoveScoreInterval():
    rep = InMemoryRepository()
    val = ParticipantValidator()
    ctr = ParticipantController(rep,val)
    
    conc1 = ctr.CreateParticipant(1,"Marioara",92)
    conc2 = ctr.CreateParticipant(2,"Cheloo",55)
    conc3 = ctr.CreateParticipant(3,"Laurentiu",97)
    conc4 = ctr.CreateParticipant(4,"Vasilica",25)
    conc5 = ctr.CreateParticipant(5,"Ferentz",64)
    
    assert conc1.GetScore() == 92
    assert conc2.GetScore() == 55
    assert conc3.GetScore() == 97
    assert conc4.GetScore() == 25
    assert conc5.GetScore() == 64
    
    ctr.RemoveScoreInterval(2,4)
    
    assert conc1.GetScore() == 92
    assert conc2.GetScore() == 0
    assert conc3.GetScore() == 0
    assert conc4.GetScore() == 0
    assert conc5.GetScore() == 64
    
    
    
def TestFilterByMultiplier():
    rep = InMemoryRepository()
    val = ParticipantValidator()
    ctr = ParticipantController(rep,val)
    
    ctr.CreateParticipant(1,"Marioara",92) 
    ctr.CreateParticipant(2,"Cheloo",55)
    ctr.CreateParticipant(3,"Laurentiu",97)
    ctr.CreateParticipant(4,"Vasilica",25)
    ctr.CreateParticipant(5,"Ferentz",64)
    
    
    
    
    assert len(rep.allpart) == 5
    ctr.FilterByMultiplier(2)
    assert len(rep.allpart) == 3

def TestFilterByLower():
    rep = InMemoryRepository()
    val = ParticipantValidator()
    ctr = ParticipantController(rep,val)
    
    ctr.CreateParticipant(1,"Marioara",92) 
    ctr.CreateParticipant(2,"Cheloo",55)
    ctr.CreateParticipant(3,"Laurentiu",97)
    ctr.CreateParticipant(4,"Vasilica",25)
    ctr.CreateParticipant(5,"Ferentz",64)
    
    assert len(rep.allpart) == 5
    ctr.FilterByLower(60)
    assert len(rep.allpart) == 3

def TestMediaForInterval():
    rep = InMemoryRepository()
    val = ParticipantValidator()
    ctr = ParticipantController(rep,val)
    
    ctr.CreateParticipant(1,"Marioara",10) 
    ctr.CreateParticipant(2,"Cheloo",10)
    ctr.CreateParticipant(3,"Laurentiu",10)
    ctr.CreateParticipant(4,"Vasilica",49)
    ctr.CreateParticipant(5,"Ferentz",52)
    
    assert ctr.MediaForInterval(1,3) == 10
    
def TestScoreMinimumForInterval():
    rep = InMemoryRepository()
    val = ParticipantValidator()
    ctr = ParticipantController(rep,val)
    
    ctr.CreateParticipant(1,"Marioara",92) 
    ctr.CreateParticipant(2,"Cheloo",55)
    ctr.CreateParticipant(3,"Laurentiu",97)
    ctr.CreateParticipant(4,"Vasilica",25)
    ctr.CreateParticipant(5,"Ferentz",64)
    
    assert ctr.ScoreMinimumForInterval(1,3) == 55
    
    
    
   
    
    
    
TestCreateParticipant()
TestRemoveScore()
TestModifyScore()
TestRemoveScoreInterval()
TestFilterByMultiplier()
TestFilterByLower()
TestMediaForInterval()
TestScoreMinimumForInterval()