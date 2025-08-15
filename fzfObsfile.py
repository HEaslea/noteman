from pathlib import Path

RDIR = Path("D:\\C++")

def testPathway(): 
    nPath = RDIR

    for f in nPath.glob("**/*.md"): 
        # getting Pathlib.WindowsPath here
      



testPathway()