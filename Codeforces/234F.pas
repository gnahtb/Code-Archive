uses
  math;
const
  inf=trunc(1E9);
var
  n,a,b,ans:longint;
  h:array[0..205] of longint;
  f:array[0..205,0..40005,0..1] of longint;

procedure enter;
var
  i:longint;
begin
  fillchar(h,sizeof(h),0);
  readln(n);
  readln(a,b);
  for i:=1 to n do read(h[i]);
end;

procedure solve;
var
  i,j,s:longint;
begin
  for i:=0 to 205 do
    for j:=0 to 40005 do
      begin
        f[i,j,0]:=inf;
        f[i,j,1]:=inf;
      end;
  s:=0; f[0,0,0]:=0;
  for i:=1 to n do
    begin
      s:=s+h[i];
      for j:=0 to a do
        if s-j<=b then
          begin
            f[i,j,0]:=min(f[i-1,j,0],f[i-1,j,1]+min(h[i-1],h[i]));
            if j>=h[i] then
              begin
                f[i,j,1]:=min(f[i,j,1],f[i-1,j-h[i],0]+min(h[i-1],h[i]));
                f[i,j,1]:=min(f[i,j,1],f[i-1,j-h[i],1]);
              end;
          end;
    end;
  ans:=inf;
  for j:=0 to a do ans:=min(ans,min(f[n,j,0],f[n,j,1]));
  if ans=inf then ans:=-1;
end;

begin
  assign(input,'input.txt'); reset(input);
  assign(output,'output.txt'); rewrite(output);
  enter;
  solve;
  writeln(ans);
  close(input);
  close(output);
end.
