# StepReader介绍

## 支持的三维实体

在MyGraduationProject\StepReader\StepClass里面所声明的三维实体是支持阅读的，如果不支持，会有提示

```c++
else {
        cout << "本条" + fileRow + "不是本程序可以处理的曲面，请检查格式" << endl;
        exit(0);
        getchar();
    }
```

根据提示，看清楚是哪一个面或者哪一个线，然后去https://ap238.org/SMRL_v8_final/data/resource_docs/geometric_and_topological_representation/sys/2_refs.htm或者找到STEP对应标准，看对应三维实体的数据结构，再在代码里面声明对应结构，根据已有的handle()处理模式，就可以对模型进行读取

## 当前进展

1. 从Manifold_solid_brep开始往下进行处理，所以上层的如颜色、context等信息没有进行处理，需要再学习。
2. 绘制用的是obj文件，目前只对圆面、圆柱面、平面进行了绘制。obj文件格式参考http://paulbourke.net/dataformats/obj/