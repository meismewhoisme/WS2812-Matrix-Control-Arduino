import csv
rows = 8
columns = 8

bmatrix = []
rmatrix=[]
gmatrix=[]
rfile = open('Red.csv', mode='r')
gfile = open('Green.csv', mode='r')
with open('Blue.csv', mode ='r')as bfile:

  bcsvFile = csv.reader(bfile)
  rcsvFile = csv.reader(rfile)
  gcsvFile = csv.reader(gfile)

  for Blines in bcsvFile:
      bmatrix.append(Blines)
  for Rlines in rcsvFile:
      rmatrix.append(Rlines)
  for Glines in gcsvFile:
      gmatrix.append(Glines)

#print(rmatrix)
#print(bmatrix)
#print(gmatrix)
 

combined = ""
combined= combined + "{"
for i in range(rows):
    combined= combined + "{"
    for j in range(columns):
        combined= combined + "{"
        combined = combined + (rmatrix[i][j]) + ","
        combined = combined + (gmatrix[i][j]) + ","
        combined = combined + (bmatrix[i][j]) + ""
        combined= combined + "}"
        if (j<rows-1):
            combined= combined + ","

    if (i<rows-1):
        combined= combined + "}, "
        
combined = combined + "}}; "
print("Your matrix is: ")
print(combined)

