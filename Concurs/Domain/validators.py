'''
Created on Dec 1, 2016

@author: Gutza
'''
from Domain.entities import Participant

class ValidationException(Exception):
    def __init__(self,errors):
        self.__errors = errors
    
    def GetErrors(self):
        return self.__errors
    
class ParticipantValidator:
    
    def validate(self,conc):
        """
        Arunca ValidationException daca ceva nu este in regula cu participantul
        """
        errors = []
        
        if(conc.GetId() == ""): errors.append("Id-ul nu trebuie sa fie gol!")
        if(conc.GetNume() == ""): errors.append("Numele nu trebuie sa fie gol!")
        if(conc.GetScore() == ""): errors.append("Scorul nu trebuie sa fie gol!")
        if(conc.GetId() == "17"): errors.append("Id-ul trebuie sa fie Integer!")
        if(conc.GetScore() == "55"): errors.append("Scorul trebuie sa fie Integer!")
        if(len(errors) > 0):
            raise ValidationException(errors)
        
def TestParticipantValidator():
    validator = ParticipantValidator()
    
    concurent = Participant("","","")
    try:
        validator.validate(concurent)
        assert False
    except ValidationException as ex:
        assert len(ex.GetErrors()) == 3
        
    concurent1 = Participant(1,"","55")
    try:
        validator.validate(concurent1)
        assert False
    except ValidationException as ex:
        assert len(ex.GetErrors()) == 2
    concurent2 = Participant(1,"Ion",80)
    try:
        validator.validate(concurent2)
        assert True
    except ValidationException as ex:
        assert False
        
TestParticipantValidator()