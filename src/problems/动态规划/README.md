## 背包问题

* 0-1背包：因为利用到本行信息，倒序保证安全更新
* 完全背包：因为利用到上一行信息，正序保证及时更新

```asm
# 组合问题
# 0-1背包：因为利用到本行信息，倒序保证安全更新
for n in nums:
    for j in range(V, n-1, -1):

# 完全背包：因为利用到上一行信息，正序保证及时更新
for n in nums:
    for j in range(n, V+1):
    
# 排列问题
# 下面的循环必然产生重复，因此一定是完全背包问题？
for j in range(1, V+1):
    for num in nums:
```


问题类型

```asm
f[j] = max(f[j], f[j-n]+v) # 最值
f[j] += f[j-n] # 方案数
f[j] |= f[j-n] # 可行性
```


其他问题
```asm
# 二维费用0-1背包：
for n, n2 in nums:
    for j in range(m, n1-1, -1):
        for k in range(n, n2-1, -1):

# 分组背包：第三层循环顺序保证每组最多拿一个物品
for k in range(K):
    for j in range(V, -1, -1):
        for n in nums[k]:
```