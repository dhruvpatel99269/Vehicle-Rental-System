pipeline {
    agent any

    stages {
        stage('Checkout Code') {
            steps {
                // Adjust this if using GitHub or other repo
                git 'https://github.com/dhruvpatel99269/Vehicle-Rental-System'
            }
        }

        stage('Compile') {
            steps {
                echo 'Compiling the C++ program...'
                sh 'g++ -std=c++17 -o rental_app main.cpp'
            }
        }

        stage('Run') {
            steps {
                echo 'Running the program...'
                // You can redirect input from a file or run interactively if on a local agent
                sh './rental_app < input.txt || true'
            }
        }
    }

    post {
        always {
            echo 'Cleaning up...'
            sh 'rm -f rental_app'
        }
    }
}
