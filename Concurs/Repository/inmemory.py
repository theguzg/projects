'''
Created on Dec 1, 2016

@author: Gutza
'''

from Domain.entities import Participant

class RepositoryException(Exception):
    pass


class InMemoryRepository :
    def __init__(self):
        self.allpart = []
       
        
    def Store(self,conc):
        """ Store este functia care adauga un participant
        conc = Participant
        """
        if conc in self.allpart:
            raise RepositoryException
        self.allpart.append(conc)
    
    def Size(self):
        """
        Numarul total de participanti
        Returneaza un Integer
        """
        return len(self.allpart)
       
    
    def Delete(self,conc):
        self.allpart.remove(conc)
    
    def GetAllParticipants(self):
        """
        Returneaza toti participantii
        """
        return list(self.allpart)
        
        
    
    
    
def TestStoreParticipant():
    concurent = Participant(1,"Ion",55)
    rep = InMemoryRepository()
    assert rep.Size() == 0
    rep.Store(concurent)
    assert rep.Size() == 1
    concurent2 = Participant(2,"Vasile",49)
    rep.Store(concurent2)
    assert rep.Size() == 2
    rep.Delete(concurent2)
    assert rep.Size() == 1

TestStoreParticipant()