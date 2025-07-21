pipeline {
    agent any

    stages {
        stage('Checkout Code') {
        steps {
            echo 'Cloning repository...'
            git branch: 'main', url: 'https://github.com/dhruvpatel99269/Vehicle-Rental-System'
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
                // Simulate user input if needed
                sh './rental_app < input.txt || true'
            }
        }

        stage('Done') {
            steps {
                echo '✅ Pipeline execution finished successfully.'
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
