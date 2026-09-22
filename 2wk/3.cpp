import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation


a, b = map(int, input().split())

t = np.linspace(0, 200, 10000)

x = np.sin(np.pi * t * a * 0.01)
y = np.sin(np.pi * t * b * 0.01)


fig, ax = plt.subplots(1, 2)

point1, = ax[0].plot([], [], 'o')
trail, = ax[0].plot([], [])


ax[0].set_xlim(-1.1, 1.1)
ax[0].set_ylim(-1.1, 1.1)


# x, y, t
c = np.round(
    np.column_stack((x, y, t)),
    3
)


# Ищем повторяющиеся координаты x,y
d, index, count = np.unique(
    c[:, :2],
    axis=0,
    return_counts=True,
    return_index=True
)


# Только повторяющиеся
mask = count > 1

index = index[mask]


# ВАЖНО: сортируем по исходному индексу,
# а значит и по времени
index = np.sort(index)


d_uni = c[index]


print("Повторяющиеся точки:")
print(d_uni)


# Убираем точки, которые слишком близко
selected = []

for point in d_uni:

    if len(selected) == 0:
        selected.append(point)
        continue

    if point[2] - selected[-1][2] >= 5:
        selected.append(point)


d_uni = np.array(selected)


print("После фильтра:")
print(d_uni)


# Рисуем найденные точки на фигуре Лиссажу
ax[0].plot(
    d_uni[:, 0],
    d_uni[:, 1],
    'o'
)


# Гистограмма X
ax[1].hist(
    d_uni[:, 0],
    bins=10
)

ax[1].set_title("Распределение X")
ax[1].set_xlabel("x")
ax[1].set_ylabel("Количество")


def update(frame):

    point1.set_data(
        [x[frame]],
        [y[frame]]
    )

    trail.set_data(
        x[:frame + 1],
        y[:frame + 1]
    )

    return point1, trail


animation = FuncAnimation(
    fig,
    update,
    frames=len(x),
    interval=0.1
)


plt.show()
