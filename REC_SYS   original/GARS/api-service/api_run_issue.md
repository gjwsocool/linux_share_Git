API是一个将recall和rank结果拼接起来的一个中介

> 把一个user_id和anime_id拼接成详细信息

### 运行顺序

必须先recall(5001端口)，然后rank(5002端口)，最后api(5003端口)

1：recall

![image-20230221211131596](/home/guojiawei/.config/Typora/typora-user-images/image-20230221211131596.png)

2：rank

![image-20230221211154048](/home/guojiawei/.config/Typora/typora-user-images/image-20230221211154048.png)

3:api

![image-20230221211305461](/home/guojiawei/.config/Typora/typora-user-images/image-20230221211305461.png)

### 运行结果

![image-20230221211340173](/home/guojiawei/.config/Typora/typora-user-images/image-20230221211340173.png)

![image-20230221211424288](/home/guojiawei/.config/Typora/typora-user-images/image-20230221211424288.png)