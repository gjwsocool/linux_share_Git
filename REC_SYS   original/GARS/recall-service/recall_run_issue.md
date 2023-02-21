recall这一部分：

> 首先：
>
> ```
> virtualenv venv --python=python3
> ```
>
> ```
> source venv/bin/activate
> ```
>
> ```
> pip install -r requirements.txt
> ```
>
> 然后不要忘记安装一下：flask
>
> ```
> pip install flask
> ```
>
> 最后运行shell脚本
>
> ```
> sh start.sh//bash start.sh
> ```

> ![image-20230221172824829](/home/guojiawei/.config/Typora/typora-user-images/image-20230221172824829.png)
>
> 如果想在命令行查看：`curl -i http:127.0.0.1:5050/recall或sim `
>
> ![image-20230221173032752](/home/guojiawei/.config/Typora/typora-user-images/image-20230221173032752.png)

> 注意：输入参数要加上？和一个=
>
> ![image-20230221173133883](/home/guojiawei/.config/Typora/typora-user-images/image-20230221173133883.png)