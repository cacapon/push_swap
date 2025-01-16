import os
import sys
import random
import copy 

class Commands:
	def __init__(self, num, arr=[]):
		self.status = "KO"
		self.a = arr
		self.b = []
		self.cmd_list = {
			"q"  : "quit",
			"sa" : self.sa,
			"sb" : self.sb,
			"ss" : self.ss,
			"pa" : self.pa,
			"pb" : self.pb,
			"a<" : self.ra,
			"b<" : self.rb,
			"r<" : self.rr,
			"a>" : self.rra,
			"b>" : self.rrb,
			"r>" : self.rrr,
			"re" : self.redo,
		}
		self.history = []
		while (len(self.a) < num):
			x = random.randint(0, 150)
			if x not in self.a:
				self.a.append(x)

	def is_clear(self):
		if sorted(self.a) == self.a and len(self.b) == 0:
			self.status = "OK"
			return True
		return False

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

	def redo(self):
		if (len(self.history) == 0):
			return
		cmd = self.history.pop()
		if cmd == "sa" or cmd == "ss":
			self._swap(self.a)
		if cmd == "sb" or cmd == "ss":
			self._swap(self.b)
		if cmd == "pa":
			self._push(self.b, self.a)
		if cmd == "pb":
			self._push(self.a, self.b)
		if cmd == "ra" or cmd == "rr":
			self._rv_rotate(self.a)
		if cmd == "rb" or cmd == "rr":
			self._rv_rotate(self.b)
		if cmd == "rra" or cmd == "rrr":
			self._rotate(self.a)
		if cmd == "rrb" or cmd == "rrr":
			self._rotate(self.b)


	def sa(self):
		self.history.append("sa")
		self._swap(self.a)

	def sb(self):
		self.history.append("sb")
		self._swap(self.b)

	def ss(self):
		self.history.append("ss")
		self._swap(self.a)
		self._swap(self.b)

	def pa(self):
		self.history.append("pa")
		self._push(self.a, self.b)
	
	def pb(self):
		self.history.append("pb")
		self._push(self.b, self.a)
	
	def ra(self):
		self.history.append("ra")
		self._rotate(self.a)
	
	def rb(self):
		self.history.append("rb")
		self._rotate(self.b)

	def rr(self):
		self.history.append("rr")
		self._rotate(self.a)
		self._rotate(self.b)
 
	def rra(self):
		self.history.append("rra")
		self._rv_rotate(self.a)
	
	def rrb(self):
		self.history.append("rrb")
		self._rv_rotate(self.b)

	def rrr(self):
		self.history.append("rrr")
		self._rv_rotate(self.a)
		self._rv_rotate(self.b)

def draw(cmds:Commands):
	os.system("clear")
	print("----------")
	print(cmds.a)
	print(cmds.b)
	print("----------")
	print(f"command counts:{len(cmds.history)}")
	print(f"cmds:{cmds.history}")
	if (len(cmds.a) != 0):
		a_max = max(cmds.a)
		a_min = min(cmds.a)
		a_max_l = cmds.a.index(a_max)
		a_max_r = (len(cmds.a) - a_max_l) % len(cmds.a)
		a_min_l = cmds.a.index(a_min)
		a_min_r = (len(cmds.a) - a_min_l) % len(cmds.a)
		print(f"a({a_max}[<{a_max_l},{a_max_r}>],{a_min}[<{a_min_l},{a_min_r}>])")
	else:
		print(f"a is empty")

def ctrl(cmds:Commands):
	in_data = input(">")
	try:
		cmd, count = in_data.split(" ")
	except ValueError:
		cmd = in_data
		count = "1"
	finally:
		return (cmds.cmd_list.get(cmd), int(count))

def update(select_cmd, count):
	for i in range(count):
		select_cmd()

def main(argv):
	cmds = Commands(argv)
	while(1):
		draw(cmds)
		if cmds.is_clear():
			break
		cmd,count = ctrl(cmds)
		if (cmd == "quit"):
			break
		if (cmd is None):
			continue
		update(cmd, count)

if __name__ == '__main__':
	main(int(sys.argv[1]))

