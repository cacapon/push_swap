import sys
import random

class Commands:
	def __init__(self):
		pass

	def _swap(self, arr:list):
		if (len(arr) < 2):
			return
		tmp    = arr[0]
		arr[0] = arr[1]
		arr[1] = tmp

	def _push(self, dst:list, src:list):
		if (len(src) == 0):
			return
		dst.insert(0, src.pop(0))

	def _rotate(self, arr:list):
		if (len(arr) == 0):
			return
		arr.append(arr.pop(0))
	
	def _rv_rotate(self, arr:list):
		if (len(arr) == 0):
			return
		arr.insert(0,arr.pop())

	def sa(self, a:list):
		print("sa")
		self._swap(a)

	def sb(self, b:list):
		print("sb")
		self._swap(b)

	def ss(self, a:list, b:list):
		print("ss")
		self._swap(a)
		self._swap(b)

	def pa(self,a:list, b:list):
		print("pa")
		self._push(a, b)
	
	def pb(self, a:list, b:list):
		print("pb")
		self._push(b, a)
	
	def ra(self, a:list):
		print("ra")
		self._rotate(a)
	
	def rb(self, b:list):
		print("rb")
		self._rotate(b)

	def rr(self, a:list, b:list):
		print("rr")
		self._rotate(a)
		self._rotate(b)
 
	def rra(self, a:list):
		print("rra")
		self._rv_rotate(a)
	
	def rrb(self, b:list):
		print("rrb")
		self._rv_rotate(b)

	def rrr(self, a:list, b:list):
		print("rrr")
		self._rv_rotate(a)
		self._rv_rotate(b)

def rand_ints_nodup(a, b, k)->list:
  ns = []
  while len(ns) < k:
    n = random.randint(a, b)
    if not n in ns:
      ns.append(n)
  return ns

def get_a_mv(x:int, a:list):
	mv = [0,0]
	# 先頭に移動させるまでの移動量を求める
	index = a.index(x)
	# index分<にずらせば先頭になる
	mv[0] = index
	# (len - index) % lenで＞になるはず
	mv[1] = (len(a) - index) % len(a)
	return mv

def get_b_mv(x:int, b:list):
	# xをbの値のどこに入れるかを求める
	mv = [0,0]
	index = -1
	if (len(b) < 2):
		return mv
	for i in range(len(b)):
		if b[i] > x and x > b[(i+1) % len(b)]:
			index = (i + 1) % len(b)
			break
	# 見つからない場合はindexは最大値の場所に合わせる
	if index == -1:
		index = b.index(max(b))
	# indexはa > x > bのbの場所
	# xはbの前におけばいいのでbを先頭にする
	mv[0] = index
	mv[1] = (len(b) - index) % len(b)
	return mv

def get_cmd_mv(a:list, b:list):
	if a[0] < a[1]:
		a_mv = -a[0]
	else:
		a_mv = a[1]
	if b[0] < b[1]:
		b_mv = -b[0]
	else:
		b_mv = b[1]

	# a,b最小の動きを求めた
	cmd_mv = [0,0,0,0]
	cmd_mv[0] = a_mv
	cmd_mv[1] = b_mv
	if a_mv > 0 and b_mv > 0:
		cmd_mv[2] = min(a_mv, b_mv)
		cmd_mv[0] -= cmd_mv[2]
		cmd_mv[1] -= cmd_mv[2]
	elif a_mv < 0 and b_mv < 0:
		cmd_mv[2] = max(a_mv, b_mv)
		cmd_mv[0] -= cmd_mv[2]
		cmd_mv[1] -= cmd_mv[2]
	# moveを求める
	cmd_mv[3] = abs(cmd_mv[0]) + abs(cmd_mv[1]) + abs(cmd_mv[2])
	return cmd_mv

def get_min_move_index(cmd_mv:list):
	# [[a,b,cmn,move]]
	min_move = 2**31 - 1
	index = -1
	for i,move in enumerate(cmd_mv):
		if move[3] < min_move:
			min_move = move[3]
			index = i
	return index

def main(n):
	# stackの準備
	cmd = Commands()
	a = rand_ints_nodup(1,n*2,n)
	b = []
	print(a)
	print(b)
	for i in range(2):
		cmd._rotate(b)
	while (len(a) > 0):
		# aの移動量を求める
		a_mv = []
		b_mv = []
		for x in a:
			a_mv.append(get_a_mv(x,a))
			b_mv.append(get_b_mv(x,b))
		# 最小の移動量を求める
		INT_MAX = 2**31-1
		cmd_mv = []
		for i in range(len(a_mv)):
			cmd_mv.append(get_cmd_mv(a_mv[i], b_mv[i]))
		min_mv = cmd_mv[get_min_move_index(cmd_mv)]
		print(f"cmd_mv:{cmd_mv}")
		print(f"min_mv:{min_mv}")
		while min_mv[0] != 0 or min_mv[1] != 0 or min_mv[2] != 0:
			if min_mv[2] < 0:
				cmd.rr(a,b)
				min_mv[2] += 1
			elif min_mv[2] > 0:
				cmd.rrr(a,b)
				min_mv[2] -= 1
			elif min_mv[0] < 0:
				cmd.ra(a)
				min_mv[0] += 1
			elif min_mv[0] > 0:
				cmd.rra(a)
				min_mv[0] -= 1
			elif min_mv[1] < 0:
				cmd.rb(b)
				min_mv[1] += 1
			elif min_mv[1] > 0:
				cmd.rrb(b)
				min_mv[1] -= 1
		cmd.pb(a,b)
		print(f"a:{a}")
		print(f"b:{b}")
	# bの一番高い数字を先頭に戻す
	b_max_mv = get_a_mv(max(b), b)
	if b_max_mv[0] < b_max_mv[1]:
		b_max_mv = [b_max_mv[0], 0]
	else:
		b_max_mv = [0, b_max_mv[1]]
	while b_max_mv[0] != 0 or b_max_mv[1] != 0:
		if b_max_mv[0] > 0:
			cmd.rb(b)
			b_max_mv[0] -= 1
		elif b_max_mv[1] > 0:
			cmd.rrb(b)
			b_max_mv[1] -= 1
	while len(b) > 0:
		cmd.pa(a, b)
	print(f"a:{a}")
	print(f"b:{b}")
	print(f"a is_sorted:{a == sorted(a)}")


main(int(sys.argv[1]))