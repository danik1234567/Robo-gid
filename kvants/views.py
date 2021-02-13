from django.shortcuts import render
from .data import it_kvant, aero_kvant, auto_kvant, hi_tech_kvant, prom_design_kvant, prom_robo_kvant


def load_it_page(request):
    return render(request, 'kvants/base_kvant.html', {'title': it_kvant.NAME,
                                                      'description': it_kvant.DESCRIPTION,
                                                      'logo_path': it_kvant.LOGO_PATH})


def load_aero_page(request):
    return render(request, 'kvants/base_kvant.html', {'title': aero_kvant.NAME,
                                                      'description': aero_kvant.DESCRIPTION,
                                                      'logo_path': aero_kvant.LOGO_PATH})


def load_auto_page(request):
    return render(request, 'kvants/base_kvant.html', {'title': auto_kvant.NAME,
                                                      'description': auto_kvant.DESCRIPTION,
                                                      'logo_path': auto_kvant.LOGO_PATH})


def load_design_page(request):
    return render(request, 'kvants/base_kvant.html', {'title': prom_design_kvant.NAME,
                                                      'description': prom_design_kvant.DESCRIPTION,
                                                      'logo_path': prom_design_kvant.LOGO_PATH})


def load_robo_page(request):
    return render(request, 'kvants/base_kvant.html', {'title': prom_design_kvant.NAME,
                                                      'description': prom_robo_kvant.DESCRIPTION,
                                                      'logo_path': prom_robo_kvant.LOGO_PATH})


def load_hi_tech_page(request):
    return render(request, 'kvants/base_kvant.html', {'title': hi_tech_kvant.NAME,
                                                      'description': hi_tech_kvant.DESCRIPTION,
                                                      'logo_path': hi_tech_kvant.LOGO_PATH})
