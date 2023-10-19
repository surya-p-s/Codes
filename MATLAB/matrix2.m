% Create a 5x5 matrix with all elements as 4
A = 4 * ones(5);

% Add the magic(5) matrix to it
B = A + magic(5);

% Find the eigenvalues of the resultant matrix B
eigenvalues = eig(B);

% Calculate the inverse of the resultant matrix B
inverse_B = inv(B);

% Display the eigenvalues and the inverse matrix
disp('Eigenvalues:');
disp(eigenvalues);
disp('Inverse of B:');
disp(inverse_B);
