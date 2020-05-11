stack<int> s1,s2;
MinStack::MinStack() {
 while(!s1.empty())
 {
 s1.pop();
 }
  while(!s2.empty())
 {
 s2.pop();
 }
}

void MinStack::push(int x) {
  s1.push(x);
  if(s2.empty())
  s2.push(x);
  else
  {
  if(x<=s2.top())
  {
  s2.push(x);
  }
  else
  s2.push(s2.top());
  }
}

void MinStack::pop() {
  if(!s1.empty())
  {
  s1.pop();
  s2.pop();
  }
}

int MinStack::top() {
  if(s1.empty())
  return -1;
  return s1.top();
}
int MinStack::getMin() {
return s2.top();
}
