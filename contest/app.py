'''
Created on Oct 22, 2017

@author: Gutza
'''

from repository.inmemory import InMemoryRepository
from controller.controller import ParticipantController
from ui.console import Console

rep = InMemoryRepository()
ctr = ParticipantController(rep)
ui = Console(ctr)

ui.showUI()