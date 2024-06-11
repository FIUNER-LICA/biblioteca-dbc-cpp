import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import datetime
import os
import argparse

parser = argparse.ArgumentParser(description="Script to perform benchmarks of contratized examples. Specify the example to use in makefile")
parser.add_argument('num_repetitions', nargs='?', default=1, type=int, help="Number of repetitions that the example is going to be executed.")
parser.add_argument('-silence', action='store_true', help='Silence outputs and save it in ./data/')
parser.add_argument('-optimization', nargs='?', default=None, type=str, help="Type of optimization.")

args = parser.parse_args()

call = f"./script.sh -r {args.num_repetitions}"
if args.optimization:
	call+=f" -o {args.optimization}"
else:
	print("There is no optimization")
os.system(call)


df = pd.read_csv("data/benchmark_output.csv")

df_grouped = df.groupby(["assert_mode", "invariant_mode"])[["real_time", "user_time", "sys_time", "avg_memory"]].mean().reset_index()


plt.figure(figsize=(14,10))
plt.suptitle("Benchmarks")
plt.subplot(221)
plt.title("Real time")
sns.barplot(df_grouped, x="assert_mode", y="real_time", hue="invariant_mode")

plt.subplot(222)
plt.title("User time")
sns.barplot(df_grouped, x="assert_mode", y="user_time", hue="invariant_mode")

plt.subplot(223)
plt.title("Sys time")
sns.barplot(df_grouped, x="assert_mode", y="sys_time", hue="invariant_mode")

plt.subplot(224)
plt.title("Avg mem")
sns.barplot(df_grouped, x="assert_mode", y="avg_memory", hue="invariant_mode")


plt.subplots_adjust(hspace=0.5)
plt.tight_layout()

if args.silence:
	hora_actual = datetime.datetime.now()

	hora_formateada = hora_actual.strftime("%Y-%m-%d_%H-%M-%S")
	plt.savefig(f"./data/{hora_formateada}.png")
else:
	plt.show()