#include <stdio.h>
#include "structures.h"
#include "utils.h"
#include "print.h"
#include "scene.h"
#include "trace.h"

t_scene *scene_init(void)
{
	t_scene *scene;
	t_object *world;
	t_object *lights;
	double ka;

	if(!(scene = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
	scene->canvas = canvas(400, 300);
	scene->camera = camera(&scene->canvas, point3(0, 0, 0));
	world = object(SP, sphere(point3(-2, 0 ,-5), 2), color3(0.5, 0, 0));
	oadd(&world, object(SP, sphere(point3(0, -1000, 0), 995), color3(1, 1, 1)));
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2), color3(0, 0.5, 0)));
	scene->world = world;
	lights = object(LIGHT_POINT, light_point(point3(0, 20, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->light = lights;
	return (scene);
}

int	main(void)
{
	int i;
	int j;
	double u;
	double v;
	double r;
	double g;
	double b;
	int		canvas_width;
	int		canvas_height;
	t_color3	pixel_color;
	t_scene *scene;
	t_canvas canv;
	t_camera cam;
	t_ray ray;
	t_object *world;

	scene = scene_init();
	printf("P3\n%d %d\n255\n", scene->canvas.width, scene->canvas.height);
	j = scene->canvas.height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			write_color(pixel_color);
			++i;
		}
		--j;
	}
	return (0);
}
