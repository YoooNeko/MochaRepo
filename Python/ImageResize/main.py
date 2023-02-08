import time
import os
from PIL import Image
import multiprocessing
from multiprocessing import Pool

ProcessPath = os.getcwd()  # 当前处理图片的路径
SavePath = ProcessPath + '\PicSave'  # 保存处理好的图片的路径

def ImageProcess(name):
    print(name + "已经开始处理处理........")
    target = Image.open(name)
    white1 = target.resize((2048, 2048))
    for x in range(0, 16):
        for y in range(0, 16):
            for curX in range(x * 128, x * 128 + 128):
                for curY in range(y * 128, y * 128 + 128):
                    white1.putpixel((curX, curY), target.getpixel((x, y)))
    SaveName = os.path.join(SavePath, name)
    white1.save(SaveName)
    print(name + "已经被处理并保存至", SavePath)

def RemFile(path):
    print("开始清空PicSave文件夹...")
    ls = os.listdir(path)
    for j in ls:
        c_path = os.path.join(path, j)
        if os.path.isdir(c_path):
            RemFile(c_path)
        else:
            os.remove(c_path)
    print("清空文件夹结束")

if __name__ == "__main__" :
    multiprocessing.freeze_support()
    start_time = time.time()

    count = 0
    ProcessPath = os.getcwd()  # 当前处理图片的路径
    SavePath = ProcessPath + '\PicSave'  # 保存处理好的图片的路径
    isExists = os.path.exists(SavePath)
    if not isExists:
        os.makedirs(SavePath)
        print("创建PicSave文件夹...")
    else:
        RemFile(SavePath)

    image = []
    datanames = os.listdir(ProcessPath)
    for i in datanames:
        if i[-4:] == '.png' and i != 'emptyImage.png':
            image.append(i)
            count = count + 1
    # 进程池
    print("正在初始化进程池...")
    poolnum = 16        # 默认是16个
    if len(image) < poolnum:    # 如果图片数量小于进程数量，则调整进程数量
        poolnum = len(image)

    pool = Pool(poolnum)

    print("开始处理图片...")
    pool.map(ImageProcess, image)
    pool.close()
    pool.join()

    end_time = time.time()
    run_time = end_time - start_time
    print("程序运行时长: ", run_time, "处理了", count, "个图片")

    input('按下回车退出...')