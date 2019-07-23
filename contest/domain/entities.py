'''
Created on Oct 22, 2017

@author: Gutza
'''


class Participant:
    def __init__(self,P1,P2,P3):
        self.__P1 = P1
        self.__P2 = P2
        self.__P3 = P3
        
    def getP1(self):
        return self.__P1
    
    def getP2(self):
        return self.__P2
    
    def getP3(self):
        return self.__P3
    
    def setP1(self,newP1):
        self.__P1 = newP1
    
    def setP2(self,newP2):
        self.__P2 = newP2
    
    def setP3(self,newP3):
        self.__P3 = newP3
    
    def getAverage(self):
        return float((self.__P1 + self.__P2 + self.__P3) / 3)
    
    
def testCreateParticipant():
    
    participant = Participant(10,6,7)
    
    assert participant.getP1() == 10
    assert participant.getP2() == 6
    assert participant.getP3() == 7
    
    
testCreateParticipant()