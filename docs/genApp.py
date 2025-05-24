import random

def generate_application_file(filename="Application_generated.txt"):
    college_names = ["VTI", "VIT", "BITS", "IITM", "IITB", "PESU", "ZOE", "GIT", "NEA", "CEC"]
    programs = ["BSC-MATH", "BTECH-MECH", "BTECH-CS", "BCOM", "BTECH-ECE", "BSC-FOR", "BTECH-AIML", "BSC-PHY"]

    unique_ranks = set()
    
    with open(filename, "w") as f:
        for i in range(1, 501):  # Generate 500 records
            while True:
                rank = random.randint(1, 500)  # Generate a random rank
                if rank not in unique_ranks:  # Check for uniqueness
                    unique_ranks.add(rank)  # Add it to the set
                    break
            
            college_program_pairs = []
            for _ in range(3):
                college = random.choice(college_names)
                program = random.choice(programs)
                college_program_pairs.append(f"{college} {program}")
            
            f.write(f"{i} {rank} {' '.join(college_program_pairs)}\n")

# Run the function to create the file
generate_application_file()
