'''
Created on Oct 23, 2017

@author: Gutza
'''

from controller.controller import ParticipantController
from domain.entities import Participant
from repository.inmemory import RepositoryException

class Console:
    def __init__(self,ctr):
        
        self.__ctr = ctr
    
    def __showAllParticipants(self):
        
        participants = self.__ctr.getAllParticipants()
        
        if len(participants) == 0:
            print("I'm really sorry young fellow, there are no participants at the moments.")
        else:
            print("P1    P2    P3")
            for participant in participants:
                print(participant.getP1(),participant.getP2(),participant.getP3())
    
    def __addParticipant(self):
        
        P1 = int(input("Please enter a score for P1 : "))
        P2 = int(input("Please enter a score for P2 : "))
        P3 = int(input("Please enter a score for P3 : "))
        
        try:
            participant = self.__ctr.createParticipant(P1, P2, P3)
            print("Participant has been saved, my Lord...")
        except RepositoryException:
            print("Duplicated participant, sorry mate")
    
    def __insertParticipant(self):
        
        P1 = int(input("Please enter a score for P1 for our new participant : "))
        P2 = int(input("Please enter a score for P2 for our new participant : "))
        P3 = int(input("Please enter a score for P3 for our new participant : "))
        position = int(input("Please input on which position shall he/she be inserted : "))
        
        self.__ctr.insertParticipant(P1, P2, P3, position)
    
    def __removeParticipant(self):
        
        position = int(input("Please input which participant shall be removed, mkay? : "))
        
        self.__ctr.remove(position)
    
    def __removeMultipleParticipants(self):
        
        position1 = int(input("Please input the first participant that shall be removed : "))
        position2 = int(input("Please input the last participant that shall be removed : "))
    
        self.__ctr.removeMultiple(position1, position2)
    
    def __replaceParticipantScore(self):
        
        participantNumber = int(input("Please inputh which participant shall have his score replaced : "))
        P = int(input("Please input which score shall be replaced : "))
        newScore = int(input("Please input his new score for that specific exam : "))
        
        self.__ctr.replace(participantNumber, P, newScore)
    
    def __showSortedParticipants(self):
        
        participants = self.__ctr.sortedParticipants()
        
        if len(participants) == 0:
            print("Sorry mate, there are no participants at the moment.")
        else:
            print("P1    P2    P3")
            for participant in participants:
                print(participant.getP1(),participant.getP2(),participant.getP3())
    
    def __showBiggerLowerEqual(self):
        
        cmd = input("Please enter the command that you want to execute on the list, choose between < = or > : ")
        score = int(input("Please enter the score that shall be used for this operation : "))
        
        participants = self.__ctr.BiggerLowerEqual(cmd,score)
        
        if len(participants) == 0:
            print("Sorry mate, there are no participants at the moment.")
        else:
            print("P1    P2    P3")
            for participant in participants:
                print(participant.getP1(),participant.getP2(),participant.getP3())
    
    def __showAverageOfAverage(self):
        
        position1 = int(input("Please input the first participant that shall be considered for this operation : "))
        position2 = int(input("Please input the last participant that shall be considered for this operation : "))
        
        average_of_average = self.__ctr.averageOfAverage(position1,position2)
        
        print("The average of those participants averages is : ",average_of_average)
    
    def __showMinOfAverage(self):
        
        position1 = int(input("Please input the first participant that shall be considered for this operation : "))
        position2 = int(input("Please input the last participant that shall be considered for this operation : "))
        
        min_of_average = self.__ctr.minOfAverage(position1,position2)
        
        print("The minimum of those participants averages is : ",min_of_average)
        
    def __showTopThree(self):
        
        participants = self.__ctr.topThree()
        
        if len(participants) == 0:
            print("Sorry mate, there are no participants at the moment.")
        else:
            print("P1    P2    P3")
            for participant in participants:
                print(participant.getP1(),participant.getP2(),participant.getP3())
    
    def __showTopFourP(self):
        
        P = int(input("Please enter on which of the exams shall be the top four executed on : "))
        
        participants = self.__ctr.topFourP(P)
        
        if len(participants) == 0:
            print("Sorry mate, there are no participants at the moment.")
        else:
            print("P1    P2    P3")
            for participant in participants:
                print(participant.getP1(),participant.getP2(),participant.getP3())
                
    def __RemoveBiggerLowerEqual(self):
        
        cmd = input("Please enter the command that you want to execute on the list, choose between < = or > : ")
        score = int(input("Please enter the score that shall be used for this operation : "))
        
        self.__ctr.removeBiggerLowerEqual(cmd,score)
        
    def Undo(self):
        self.__ctr.undo()
        
    def showUI(self):
        
        out_of_here = 1
        
        print("Welcome to our programming contest! For the commands bellow, just type the number for that specific command. Thank you and enjoy!")
        print("0. Exit the program.")
        print("1. Show all of the participants.")
        print("2. Add a participant. ")
        print("3. Insert a participant on a specific position.")
        print("4. Remove a participant.")
        print("5. Remove multiple participants.")
        print("6. Replace the score of a participant.")
        print("7. Show the participants sorted in decreasing order by their average score.")
        print("8. Show participants that have an average score lower, equal or higher than a specific score.")
        print("9. Show the average of the average scores of a specific number of participants.")
        print("10. Show the minimum average score of a specific number of participants.")
        print("11. Show the top three participants, sorted in decreasing order by their average score.")
        print("12. Show the top four participants, soreded in decreasing order by a specific exam.")
        print("13. Removes the participants that have their average score lower, equal or higher than a specific score.")
        print("14. Undo the last operation that has been done on the participant list.")
        
        while out_of_here == 1:
            
            cmd = int(input("Insert your command number here : "))
            
            
            
            if cmd == 1:
                self.__showAllParticipants()
            
            if cmd == 2:
                self.__addParticipant()
            
            if cmd == 3:
                self.__insertParticipant()
            
            if cmd == 4:
                self.__removeParticipant()
            
            if cmd == 5:
                self.__removeMultipleParticipants()
            
            if cmd == 6:
                self.__replaceParticipantScore()
            
            if cmd == 7:
                self.__showSortedParticipants()
            
            if cmd == 8:
                self.__showBiggerLowerEqual()
            
            if cmd == 9:
                self.__showAverageOfAverage()
            
            if cmd == 10:
                self.__showMinOfAverage()
            
            if cmd == 11:
                self.__showTopThree()
            
            if cmd == 12:
                self.__showTopFourP()
            
            if cmd == 13:
                self.__RemoveBiggerLowerEqual()
            
            if cmd == 14:
                self.Undo()
                
            if cmd == 0:
                out_of_here = 0
        
    
    
        
        
            
        
        
    
    
        
    
        
        
        