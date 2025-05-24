import random

def generate_seat_matrix_file(filename="SeatMatrix_generated.txt"):
    college_names = ["VTI", "VIT", "BITS", "IITM", "IITB", "PESU", "ZOE", "GIT", "NEA", "CEC"]
    programs = ["BSC-MATH", "BTECH-MECH", "BTECH-CS", "BCOM", "BTECH-ECE", "BSC-FOR", "BTECH-AIML", "BSC-PHY"]

    with open(filename, "w") as f:
        # Generate entries for each college-program combination
        for college in college_names:
            for program in programs:
                num_seats = random.randint(10, 20)
                f.write(f"{college} {program} {num_seats}\n")

# Run the function to create the file
generate_seat_matrix_file()