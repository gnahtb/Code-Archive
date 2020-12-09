{$MODE OBJFPC}
uses
  gstack,
  math;
type
  TIntStack=specialize TStack<longint>;
var
  a,b,f,t:array[0..505] of longint;
  n,m,i,j,cur,ans:longint;
  flag:boolean;
  stack:TIntStack;
begin
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  fillchar(f,sizeof(f),0);
  readln(n);
  for i:=1 to n do read(a[i]);
  readln(m);
  for i:=1 to m do read(b[i]);
  ans:=0;
  for i:=1 to n do
    begin
      cur:=0;
      for j:=1 to m do
        begin
          if (a[i]=b[j]) and (f[j]<f[cur]+1) then
            begin
              f[j]:=f[cur]+1;
              t[j]:=cur;
              ans:=max(ans,f[j]);
            end;
          if (a[i]>b[j]) and (f[j]>f[cur]) then cur:=j;
        end;
    end;
  writeln(ans);
  if ans>0 then
    begin
      stack:=TIntStack.create;
      for i:=1 to m do
        if f[i]=ans then break;
      while i>0 do
        begin
          stack.push(b[i]);
          i:=t[i];
        end;
      while not stack.isEmpty do
        begin
          write(stack.top,' ');
          stack.pop;
        end;
    end;
end.
