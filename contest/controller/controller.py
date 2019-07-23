'''
Created on Oct 22, 2017

@author: Gutza
'''

from domain.entities import Participant
from repository.inmemory import InMemoryRepository
from repository.inmemory import RepositoryException
import copy

class ParticipantController:
    def __init__(self,rep):
        
        self.rep = rep
        self.backup = []
    
    def register(self):
        self.backup.append(copy.deepcopy(self.rep.allparticipants))
        
        if len(self.backup) > 10:
            self.backup.pop(0)
    
    def undo(self):
        
        if len(self.backup) > 1:
            position = len(self.backup)-2
            self.rep.allparticipants=[]
            self.rep.allparticipants=copy.deepcopy(self.backup[position])
            self.backup.pop(position+1)
    
    def createParticipant(self,P1,P2,P3):
        
        participant = Participant(P1,P2,P3)
        
        self.rep.Store(participant)
        self.register()
        
        return participant
    
    def insertParticipant(self,P1,P2,P3,position):
        
        self.rep.Insert(P1,P2,P3,position)
        self.register()
    
    def remove(self,position):
        
        self.rep.Remove(position)
        self.register()
        
    def removeMultiple(self,position1,position2):
        
        self.rep.removeMultiple(position1,position2)
        self.register()
    
    def replace(self,participantNumber,P,newScore):
        
        self.rep.Replace(participantNumber,P,newScore)
        self.register()
    
    def sortedParticipants(self):
        
        return sorted(self.rep.allparticipants, key=lambda participant: participant.getAverage(),reverse = True)
        
        '''for i in range(0,len(self.rep.allparticipants))
            if self.rep.allparticipants[i].getAverage() < self.rep.allparticipants[i].getAverage():
                auxiliary = self.rep.allparticipants'''
        
    
    def BiggerLowerEqual(self,cmd,score):
        
        auxiliary_list = []
        
        if cmd == "<":
            for participant in self.rep.allparticipants:
                if participant.getAverage() < score:
                    auxiliary_list.append(participant)
        elif cmd == "=":
            for participant in self.rep.allparticipants:
                if participant.getAverage() == score:
                    auxiliary_list.append(participant)
        elif cmd == ">":
            for participant in self.rep.allparticipants:
                if participant.getAverage() > score:
                    auxiliary_list.append(participant)
        
        return auxiliary_list
    
    def averageOfAverage(self,position1,position2):
        
        amount = 0
        number_of_elements = 0
        
        while position1 <= position2:
            amount = amount + self.rep.allparticipants[position1].getAverage()
            position1 = position1 + 1
            number_of_elements = number_of_elements + 1
        
        return float(amount / number_of_elements)
    
    def minOfAverage(self,position1,position2):
        
        auxiliary_list = []
        
        while position1 <= position2:
            auxiliary_list.append(self.rep.allparticipants[position1].getAverage())
            position1 = position1 + 1
        
        return min(auxiliary_list)
    
    def topThree(self):
        
        auxiliary_list = sorted(self.rep.allparticipants, key=lambda participant: participant.getAverage(),reverse = True)
        
        return auxiliary_list[:3]
    
    def topFourP(self,P):
        
        auxiliary_list = []
        
        if P == 1:
            auxiliary_list = sorted(self.rep.allparticipants, key=lambda participant: participant.getP1(),reverse = True)
        elif P == 2:
            auxiliary_list = sorted(self.rep.allparticipants, key=lambda participant: participant.getP2(),reverse = True)
        elif P == 3:
            auxiliary_list = sorted(self.rep.allparticipants, key=lambda participant: participant.getP3(),reverse = True)
        
        return auxiliary_list[:4]
    
    def removeBiggerLowerEqual(self,cmd,score):
        
        if cmd == "<":
            for i in range(0,len(self.rep.allparticipants)):
                if self.rep.allparticipants[i].getAverage() < score:
                    self.rep.allparticipants[i].setP1(0)
                    self.rep.allparticipants[i].setP2(0)
                    self.rep.allparticipants[i].setP3(0)
                    
        elif cmd == "=":
            for i in range(0,len(self.rep.allparticipants)):
                if self.rep.allparticipants[i].getAverage() == score:
                    self.rep.allparticipants[i].setP1(0)
                    self.rep.allparticipants[i].setP2(0)
                    self.rep.allparticipants[i].setP3(0)
                    
        elif cmd == ">":
            for i in range(0,len(self.rep.allparticipants)):
                if self.rep.allparticipants[i].getAverage() > score:
                    self.rep.allparticipants[i].setP1(0)
                    self.rep.allparticipants[i].setP2(0)
                    self.rep.allparticipants[i].setP3(0)
        
        self.register()
        
    def getAllParticipants(self):
        
        return self.rep.getAllParticipants()
    

def testCreateParticipant():
    
    rep = InMemoryRepository()
    ctr = ParticipantController(rep)
    participant = ctr.createParticipant(5, 10, 15)
    
    assert participant.getP1() == 5
    assert participant.getP2() == 10
    assert participant.getP3() == 15
    assert participant.getAverage() == 10
    
    allparticipants = ctr.getAllParticipants()
    
    assert len(allparticipants) == 1
    assert allparticipants[0] == participant

    try :
        participant = ctr.createParticipant(1,5,10)
        assert True
    except RepositoryException :
        assert False
        
    
def testInsertParticipant():
    
    rep = InMemoryRepository()
    ctr = ParticipantController(rep)
    participant = ctr.createParticipant(5, 10, 15)
    
    assert participant.getP1() == 5
    assert participant.getP2() == 10
    assert participant.getP3() == 15
    assert participant.getAverage() == 10
    
    ctr.insertParticipant(2, 4, 3, 0)
    allparticipants = ctr.getAllParticipants()
    
    assert participant.getP1() == 2
    assert participant.getP2() == 4
    assert participant.getP3() == 3
    assert participant.getAverage() == 3
    
    assert len(allparticipants) == 1

def testRemoveParticipants():
    
    rep = InMemoryRepository()
    ctr = ParticipantController(rep)
    participant = ctr.createParticipant(5, 10, 15)
    participant1 = ctr.createParticipant(2, 4, 3)
    
    assert participant.getP1() == 5
    assert participant.getP2() == 10
    assert participant.getP3() == 15
    
    assert participant1.getP1() == 2
    assert participant1.getP2() == 4
    assert participant1.getP3() == 3
    
    ctr.remove(0)
    
    assert participant.getP1() == 0
    assert participant.getP2() == 0
    assert participant.getP3() == 0
    
    ctr.insertParticipant(5, 10, 15, 0)
    
    ctr.removeMultiple(0, 1)
    
    assert participant.getP1() == 0
    assert participant.getP2() == 0
    assert participant.getP3() == 0
    
    assert participant1.getP1() == 0
    assert participant1.getP2() == 0
    assert participant1.getP3() == 0
    
    ctr.insertParticipant(5, 10, 15, 0)
    ctr.insertParticipant(2, 4, 3, 1)
    
    participant2 = ctr.createParticipant(5, 5, 5)
    participant3 = ctr.createParticipant(8, 8, 8)
    
    assert participant3.getAverage() == 8
    
    ctr.removeBiggerLowerEqual("<", 6)
    
    assert participant1.getP1() == 0
    assert participant1.getP2() == 0
    assert participant1.getP3() == 0
    
    assert participant2.getP1() == 0
    assert participant2.getP2() == 0
    assert participant2.getP3() == 0
    
def testReplaceScore():
    
    rep = InMemoryRepository()
    ctr = ParticipantController(rep)
    participant = ctr.createParticipant(5, 10, 15)
    
    assert participant.getP2() == 10
    
    ctr.replace(0, 2, 20)
    
    assert participant.getP2() == 20


    

testReplaceScore()    
testRemoveParticipants()    
testCreateParticipant()
testInsertParticipant()
    
    
            
    
    
    
    
    
            
        
        
    
