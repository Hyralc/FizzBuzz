import pytest
import time
import git
import os

@pytest.fixture
def get_repo(scope="session", autouse = True):
	
	return git.Repo.clone_from('https://github.com/AntaresSimulatorTeam/Antares_Simulator_Tests.git', os.getcwd() + os.sep + 'Antares_Simulator_Tests')


# print("hello")

def test_getRepo(get_repo):
	# cloned_repo = get_repo
	assert 0 == 0

def test_one():
	time.sleep(1)
	assert 1 == 1
	
def test_two():
	time.sleep(1)
	
	assert 2 == 2

def test_three():
	time.sleep(1)
	assert 3 == 3
