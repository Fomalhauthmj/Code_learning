import os
import os.path
import shutil
rootdir = "C:\\Users\\lenovo\\OneDrive\\ACM\\AtCoder"
if __name__ == "__main__":
    for dirpath, dirnames, filenames in os.walk(rootdir):
        for filename in filenames:
            if not os.path.exists(rootdir+"/"+filename[0:6]):
                os.mkdir(rootdir+"/"+filename[0:6])
            shutil.move(dirpath+"/"+filename,rootdir+"/"+filename[0:6])
            print(filename[0:6])
