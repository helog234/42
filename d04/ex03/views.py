from django.shortcuts import render

# Create your views here.
def fifty_shades_of_bic(request):
    rows = []
    for i in range(50):
        # Calculer intensité (0 a 255 pour les nuances RGB max)
        intensity = int((i / 49) * 255)
        hex_val = format(intensity, '02x')
        
        row = {
            'black': f"#{hex_val}{hex_val}{hex_val}",
            'red': f"#{hex_val}0000",
            'blue': f"#0000{hex_val}",
            'green': f"#00{hex_val}00"
        }
        rows.append(row)
    
    return render(request, 'ex03/index.html', {'rows': rows})