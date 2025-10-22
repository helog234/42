from django.shortcuts import render
from .forms import MyForm
from django.conf import settings
import os
from datetime import datetime

def index(request):
    # Control the method
    if request.method == 'POST':
        # Process the form
        form = MyForm(request.POST)
        if form.is_valid():
            # Process the valid form data
            text = form.cleaned_data['text']
            # Log the text to the log file
            with open(settings.LOG_FILE, 'a') as log_file:
                log_file.write(f"{datetime.now().strftime('%Y-%m-%d %H:%M:%S')} - {text}\n")
    else:
        # Display the form
        form = MyForm()
    
    history = []
    # Load the history from the log file
    if os.path.exists(settings.LOG_FILE):
        # Read the log file
        with open(settings.LOG_FILE, 'r') as log_file:
            for line in log_file:
                history.append(line.strip())
    return render(request, 'ex02/index.html', {
        'form': form,
        'history': history
    })