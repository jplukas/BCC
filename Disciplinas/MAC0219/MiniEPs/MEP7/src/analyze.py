#!/usr/bin/python

import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O (e.g. pd.read_csv)
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.linear_model import LinearRegression

data = pd.read_csv('out.csv')
print(data.head())
data['time'] = pd.to_numeric(data['time'].str.replace('s', ''))
print(f"Tempo total: {data.time.sum()} segundos")
ifs = data['ifs'].unique().tolist()
fig, axs = plt.subplots(len(ifs), 1)
fig.set_size_inches(20, 60)

for ifn in range(len(ifs)):
    df_0 = data[data['ifs'] == ifs[ifn]]
    for val in df_0['threads'].unique().tolist():
        t = df_0[df_0['threads'] == val]
        axs[ifn].plot(t['v_size'], t['time'], label=f"{val} threads")
        axs[ifn].title.set_text(f"IF={ifs[ifn]}")
    axs[ifn].legend()
plt.show()
    
plt.figure(figsize=(20,10))
dt_corr = data.corr()
sns.heatmap(dt_corr, annot=True)
plt.show()

def insp(x):
    return pd.Series({'lin':LinearRegression().fit(x[['v_size']], x.time).coef_[0]})

grouped = data.groupby(['ifs', 'threads'], as_index=False).apply(insp)

fig2, ax = plt.subplots()
ax.set_yscale('log')
for val in grouped['ifs'].unique().tolist():
    t = grouped[grouped['ifs'] == val]
    ax.plot(t['threads'], t['lin'], label=f"IF={val}")
ax.legend()
plt.show()