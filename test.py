import os
import os.path
import shutil
rootdir = "C:\\Users\\lenovo\\OneDrive"
if __name__ == "__main__":
    cnt = 0
    lines = 0
    for dirpath, dirnames, filenames in os.walk(rootdir):
        for filename in filenames:
            if filename.endswith('.cpp'):
                cnt += 1
                #print(dirpath+'\\'+filename)
                try:
                    temp = len(open(dirpath + '\\'+filename,'r',encoding=' UTF - 8 ').readlines())
                except UnicodeDecodeError:
                    temp = len(open(dirpath + '\\'+filename,'r').readlines())
                lines += temp
                print(cnt, filename,temp,lines)
    print("总计:",cnt,lines)
