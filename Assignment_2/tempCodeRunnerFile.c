trcmp(tmp->name, val) == 0)
        {
            if (p == 1)
                printf("ID: %d, %s, %d, %s, %s, %s, %d, %d, %d\n", tmp->id, tmp->name, tmp->price, tmp->company, tmp->camera, tmp->colour, tmp->RAM, tmp->battery, tmp->removable_battery);
            return tmp->price;
        }