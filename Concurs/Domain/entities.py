'''
Created on Dec 1, 2016

@author: Gutza
'''

class Participant:
    def __init__(self,idpart,nume,scor):
        """
        Creaza un nou participant cu un id , scor si nume dat
        nume = string
        id , scor = integer
        """
        self.__idpart = idpart
        self.__nume = nume
        self.__scor = scor
    
    def SetScore(self,scor):
        self.__scor = scor
    def GetId(self):
        return self.__idpart
    def GetNume(self):
        return self.__nume
    def GetScore(self):
        return self.__scor
    

def TestCreateParticipant():
    concurent = Participant(1,"Ion",67)
    assert concurent.GetId() == 1
    assert concurent.GetNume() == "Ion"
    assert concurent.GetScore() == 67
    concurent.SetScore(0)
    assert concurent.GetScore() == 0

TestCreateParticipant()       