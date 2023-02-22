import os
import shutil
import stat
import tkinter
import tkinter.messagebox
from tkinter import *
from tkinter import filedialog
import subprocess

MoveFileName = ""   #文件名
src = ""     # 被移动的目录
dst = ""     # 被移动的目录的目的地

# 移动目标目录
def DirMove(src_folder, dst_folder):
    global MoveFileName
    try:
        # 创建目标文件夹（如果不存在）
        if not os.path.exists(dst_folder + MoveFileName):
            os.makedirs(dst_folder + MoveFileName)

        # 递归移动文件夹，并保留用户权限
        # xcopy 命令
        xcopy_cmd = 'xcopy "{0}" "{1}" /E /H /K /X /Y /B /C'.format(src_folder, dst_folder + MoveFileName)

        # 使用 subprocess 调用 xcopy 命令
        subprocess.call(xcopy_cmd, shell=True)
        tkinter.messagebox.showinfo(title="success", message="移动成功")
        shutil.rmtree(src_folder)

    except Exception as e:
        tkinter.messagebox.showerror(title="success", message=f"移动文件夹时出错：{e}")

# 获取被移动的文件名
def GetLinkDes(src, type):
    global MoveFileName
    strTemp = src
    for index in range(len(strTemp) - 1, -1, -1):
        if strTemp[index] != '/':
            continue
        else:
            if strTemp[index] == '/':
                if type == True:
                    MoveFileName = strTemp[index + 1:len(strTemp)]
                    print(MoveFileName)
                return strTemp[0:index]

def select_folder_src():
    # 文件夹选择
    global src
    src = filedialog.askdirectory() # 使用askdirectory函数选择文件夹
    vSrc.set(src)

def select_folder_des():
    # 文件夹选择
    global dst
    dst = filedialog.askdirectory() # 使用askdirectory函数选择文件夹
    vDst.set(dst)

def OnMove():
    global src, dst, MoveFileName

    if len(src) == 0 or len(dst) == 0:
        tkinter.messagebox.showerror(title="Eat Shit!", message="不填路径的话，先Eat Shit")
        return

    if src == dst:
        tkinter.messagebox.showerror(title="？？？？", message="全填一样的话，先死个horse")
        return

    bContinue = tkinter.messagebox.askyesno("古德", "继续？")
    if bContinue == False:
        return

    # 获取一下被移动的目录名
    GetLinkDes(src, True)
    # 移动目录
    DirMove(src, dst)

    # 建立软链接
    mklinkSrc = src                       # 创建的地点
    mklinkDes = dst + '/' + MoveFileName  # 被创建软链接的目录
    os.chmod(mklinkDes, stat.S_IWRITE)      # 加权限不然没法做软链接
    os.symlink(mklinkDes, mklinkSrc)        # 建立软链接

if __name__ == '__main__':
    global vSrc
    global vDst
    root = Tk()
    root.title("ShitDuck")
    root.geometry('640x400+900+500')

    vSrc = tkinter.StringVar()
    vDst = tkinter.StringVar()
    tkinter.Label(root, text="目标目录：").grid(column = 0, row = 0, rowspan = 3)
    tkinter.Label(root, text="目的目录：").grid(column=0, row=5, rowspan=3)
    tkinter.Entry(root, state=DISABLED, textvariable=vSrc, width = 50).grid(column = 1, row = 0, rowspan = 3)
    tkinter.Entry(root, state=DISABLED, textvariable=vDst, width = 50).grid(column = 1, row = 5, rowspan = 3)
    tkinter.Button(root, text = "选择目标目录", command = select_folder_src).grid(column = 10, row = 0)
    tkinter.Button(root, text = "选择目的目录", command = select_folder_des).grid(column = 10, row = 5)
    tkinter.Button(root, text = "确定", command = OnMove).grid(column = 1, row = 8)

    root.mainloop()