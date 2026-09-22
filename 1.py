import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation
a, b = map(int, input().split())
t = np.linspace(0, 200, 10000)
x = np.sin(np.pi*t*a*0.01)
y = np.sin(np.pi*t*b*0.01)

fig, ax = plt.subplots(1, 2)
point1, = ax[0].plot([], [], 'o')
point2, = ax[1].plot([], [], 'o')
trail, = ax[0].plot([], [])

ax[0].set_xlim(-1.1, 1.1)
ax[0].set_ylim(-1.1, 1.1)

c = np.round(np.column_stack((x, y, t)), 2)

d, index, count = np.unique(c[:, :2], axis=0, return_counts=True, return_index=True)

mask = count > 1

d_uni = c[index[mask]]
print(d_uni)
selected = []

for point in d_uni:
    if len(selected) == 0:
        selected.append(point)
        continue

    if point[2] - selected[-1][2] >= 1:
        selected.append(point)

d_uni = np.array(selected)
print(d_uni)
plt.hist(d_uni)
def update(frame):
    point1.set_data([x[frame]], [y[frame]])
    # рисуем след от начала до текущей точки

    trail.set_data(x[:frame + 1], y[:frame + 1])
    return point1, trail


# Создаём анимацию
animation = FuncAnimation(
    fig,
    update,
    frames=len(x),
    interval=1
)

plt.show()
plt.show()
