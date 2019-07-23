'''
Created on Oct 22, 2017

@author: Gutza
'''

from domain.entities import Participant

class RepositoryException(Exception):
    pass

class InMemoryRepository:
    def __init__(self):
        self.allparticipants = []
    
    def Store(self,participant):
        
        if participant in self.allparticipants:
            raise RepositoryException
        self.allparticipants.append(participant)
    
    def Remove(self,position):
        self.allparticipants[position].setP1(0)
        self.allparticipants[position].setP2(0)
        self.allparticipants[position].setP3(0)
    
    def removeMultiple(self,position1,position2):
        while position1 <= position2:
            self.allparticipants[position1].setP1(0)
            self.allparticipants[position1].setP2(0)
            self.allparticipants[position1].setP3(0)
            
            position1 += 1     
    
    def Replace(self,participantNumber,P,newScore):
        if P == 1:
            self.allparticipants[participantNumber].setP1(newScore)
        elif P == 2:
            self.allparticipants[participantNumber].setP2(newScore)
        elif P == 3:
            self.allparticipants[participantNumber].setP3(newScore)
    
    def Insert(self,P1,P2,P3,position):
        self.allparticipants[position].setP1(P1)
        self.allparticipants[position].setP2(P2)
        self.allparticipants[position].setP3(P3)
    
    def Size(self):
        return len(self.allparticipants)
        
    def getAllParticipants(self):
        return list(self.allparticipants)
    
def testStoreParticipant():
    participant1 = Participant(10,5,12)
    rep = InMemoryRepository()
    
    assert rep.Size() == 0
    rep.Store(participant1)
    assert rep.Size() == 1
    participant2 = Participant(6,6,6)
    rep.Store(participant2)
    assert rep.Size() == 2

testStoreParticipant()
    
    
    