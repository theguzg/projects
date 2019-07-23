'''
Created on Dec 15, 2016

@author: Gutza
'''

from Controller.controller import ParticipantController
from Domain.entities import Participant
from Repository.inmemory import RepositoryException
from Domain.validators import ValidationException

class Console:
    def __init__(self,ctr):
        self.__ctr = ctr
    
    def __ShowAllParticipants(self):
        """
        Printeaza toti participantii
        Output :
            Id-ul participantului, Numele participantului, Scorul participantului ( se repeta pentru toti participantii aflati in lista de participanti
        """
    
        participants = self.__ctr.GetAllParticipants()
        
        if len(participants) == 0:
            print("Nu exista nici un participant in momentul actual.")
        else:
            print("Id    Nume    Scor")
            for participant in participants:
                print(participant.GetId(),participant.GetNume(),participant.GetScore())
    
    def __AddParticipant(self):
        """
        Adauga un participant citit de la tastatura
        Input :
            idconc = integer , id-ul participantului
            numeconc = string , numele participantului
            scorconc = integer , scorul participantului
        """
        
        idconc = int(input("Dati id-ul participantului : "))
        numeconc = input("Dati numele participantului : ")
        scorconc = int(input("Dati scorul participantului : "))
        
        try:
            conc = self.__ctr.CreateParticipant(idconc, numeconc, scorconc)
            print("Participantul " + conc.GetNume() + " a fost salvat..")
        except RepositoryException:
            print("Duplicated student idSt")
        except ValidationException as ex:
            print(ex.getErrors())
    
    def __RemoveParticipantScore(self):
        """
        Sterge scorul unui participant
        Input :
            id_participant = integer , reprezinta id-ul participantului pentru care stergem scorul
        """
        id_participant = int(input("Dati id-ul participantului caruia vreti sa ii stergeti scorul :"))
        
        self.__ctr.RemoveScore(id_participant)
        
    def __RemoveParticipantScoreForInterval(self):
        """
        Sterge scorul pentru un interval de participanti
        Input :
            limita_stanga = integer , limita stanga a intervalului
            limita_dreapta = integer , limita dreapta a intervalului
        """
        
        limita_stanga = int(input("Dati limita stanga a intervalului :"))
        limita_dreapta = int(input("Dati limita dreapta a intervalului :"))
        
        self.__ctr.RemoveScoreInterval(limita_stanga,limita_dreapta)
    
    def __ModifyParticipantScore(self):
        """
        Modifica scorul unui participant
        Input :
            id_participant = integer, id-ul participantului pentru care modificam scorul
            scor = integer , noul scor al participantului
        """
        id_participant = int(input("Dati id-ul participantului pentru care modificati scorul :"))
        scor = int(input("Dati noul scor pe care il atribuiti participantului :"))
        
        self.__ctr.ModifyScore(id_participant,scor)
    
    def __FilterByNumberForParticipants(self):
        """
        Sterge participantii care nu au scorul divizibil cu un numar dat
        Input :
            number = integer , numarul pentru care se realizeaza filtrarea
        """
        number = int(input("Dati numarul la care sa se divida scorul participantilor :"))
        
        self.__ctr.FilterByMultiplier(number)
    
    def __FilterByLowerForParticipants(self):
        """
        Sterge participantii care au scorul mai mic decat un numar dat
        Input :
            number = integer , numarul pentru care se realizeaza filtrarea
        """
        number = int(input("Dati numarul pentru a sterge participantii care au scorul mai mic decat acest numar :"))
        
        self.__ctr.FilterByLower(number)
    
    def __MediaForIntervalParticipants(self):
        """
        Afiseaza media aritmetica a scorurilor unui interval de participanti
        Input :
            limita_stanga = integer , reprezinta limita stanga a intervalului
            limita_dreapta =  integer , reprezinta limita dreapta a intervalului
        Output :
            media = float , reprezinta media aritmetica a scorurilor participantilor din intervalul dat
        """
        limita_stanga = int(input("Dati limita stanga a intervalului :"))
        limita_dreapta = int(input("Dati limita dreapta a intervalului :"))
        
        media = self.__ctr.MediaForInterval(limita_stanga,limita_dreapta)
        print("Media aritmetica a scorurilor din intervalul dat este : ",media)
    
    def __ScoreMinimumForIntervalParticipants(self):
        """
        Afiseaza cel mai mic scor al unui interval de participanti 
        Input :
            limita_stanga = integer , reprezinta limita stanga a intervalului
            limita_dreapta =  integer , reprezinta limita dreapta a intervalului
        Output :
            minim = integer , reprezinta scorul minim al intervalului de participanti
        """
        limita_stanga = int(input("Dati limita stanga a intervalului :"))
        limita_dreapta = int(input("Dati limita dreapta a intervalului :"))
        
        minim = self.__ctr.ScoreMinimumForInterval(limita_stanga,limita_dreapta)
        print("Scorul minim al intervalului este :",minim)
    
    def __ShowByLower(self):
        """
        Afiseaza participantii care au scorul mai mic decat un numar dat
        Input :
            number = integer , reprezinta numarul pentru care scorul participantului trebuie sa fie mai mic pentru a fi afisat
        Output :
            Participant Id, Participant Name, Participant Score , doar participantii care au scorul mai mic decat numarul dat
        """
        number = int(input("Dati numarul pentru a afisa participantii care au scorul mai mic decat acest numar :"))
        
        participants = self.__ctr.GetAllParticipants()
        
        if len(participants) == 0:
            print("Nu exista nici un participant in lista!")
        else:
            print("Id    Nume    Scor")
            for participant in participants:
                if participant.GetScore() < number:
                    print(participant.GetId(),participant.GetNume(),participant.GetScore())
    
    def __ShowSortedParticipants(self):
        """
        Afiseaza participantii sortati dupa scor
        Output :
            Participant Id, Participant Name, Participant Score ,sortati dupa scor
        """
        
        participants = self.__ctr.GetAllParticipants()
        
        if len(participants) == 0:
            print("Nu exista nici un participant in lista!")
        else:
            for participant in range(len(participants)-1,0,-1):
                pozMax = 0
                for poz in range(1,participant+1):
                    if participants[poz].GetScore() > participants[pozMax].GetScore():
                        pozMax = poz
                participant_aux = participants[participant]
                participants[participant] = participants[pozMax]
                participants[pozMax] = participant_aux
                
            
            print("Id    Nume    Scor")
            for participant in participants:
                print(participant.GetId(),participant.GetNume(),participant.GetScore())
    
    def __ShowByUpperSorted(self):
        """
        Afiseaza participantii care au scorul mai mare decat un numar dat
        Input :
            number = integer , reprezinta numarul pentru care scorul participantului trebuie sa fie mai mic pentru a fi afisat
        Output :
            Participant Id, Participant Name, Participant Score , doar participantii care au scorul mai mare decat numarul dat, sortati
        """
        number = int(input("Dati numarul pentru a afisa participantii care au scorul mai mic decat acest numar :"))
        
        participants = self.__ctr.GetAllParticipants()
        
        if len(participants) == 0:
            print("Nu exista nici un participant in lista!")
        else:
            for participant in range(len(participants)-1,0,-1):
                pozMax = 0
                for poz in range(1,participant+1):
                    if participants[poz].GetScore() > participants[pozMax].GetScore():
                        pozMax = poz
                participant_aux = participants[participant]
                participants[participant] = participants[pozMax]
                participants[pozMax] = participant_aux
                
            print("Id    Nume    Scor")
            for participant in participants:
                if participant.GetScore() > number:
                    print(participant.GetId(),participant.GetNume(),participant.GetScore())
    
    def __ShowForIntervalMultiply(self):
        """
        Afiseaza participantii care sunt divizibili cu 10
        """
        
        participants = self.__ctr.GetAllParticipants()
        
        if len(participants) == 0:
            print("Nu exista nici un participant in lista!")
        else:
            print("Id    Nume    Scor")
            for participant in participants:
                if participant.GetScore() % 10 == 0:
                    print(participant.GetId(),participant.GetNume(),participant.GetScore())
    def Undo(self):
        self.__ctr.und()
        
    
    def ShowUI(self):
        
        iesire = 1
        
        print("show_participants")
        print("add_participant")
        print("remove_score")
        print("remove_score_interval")
        print("modify_score")
        print("filter_by_number")
        print("filter_by_lower")
        print("media_for_interval")
        print("min_score_for_interval")
        print("show_by_lower")
        print("show_sorted")
        print("show_by_upper_sorted")
        print("show_divided_by_10")
        print("undo")
        print("exit")
        
        while iesire == 1:
            
            cmd = input("Give command :")
            
            
            if cmd == "show_participants":
                self.__ShowAllParticipants()
            
            if cmd == "add_participant":
                self.__AddParticipant()
            
            if cmd == "remove_score":
                self.__RemoveParticipantScore()
            
            if cmd == "remove_score_interval":
                self.__RemoveParticipantScoreForInterval()
            
            if cmd == "modify_score":
                self.__ModifyParticipantScore()
            
            if cmd == "filter_by_number":
                self.__FilterByNumberForParticipants()
            
            if cmd == "filter_by_lower":
                self.__FilterByLowerForParticipants()
            
            if cmd == "media_for_interval":
                self.__MediaForIntervalParticipants()
            
            if cmd == "min_score_for_interval":
                self.__ScoreMinimumForIntervalParticipants()
            
            if cmd == "show_by_lower":
                self.__ShowByLower()
            
            if cmd == "show_sorted":
                self.__ShowSortedParticipants()
            
            if cmd == "show_by_upper_sorted":
                self.__ShowByUpperSorted()
            
            if cmd == "show_divided_by_10":
                self.__ShowForIntervalMultiply()
            
            if cmd == "undo":
                self.Undo()
            
            if cmd == "exit":
                iesire = 0
                
            
            
            
    
                    