.syntax unified
	.align 2, 0
	.global task_poo_mapbee_3
	.thumb
	.thumb_func
	.type task_poo_mapbee_3, %function
task_poo_mapbee_3: @ 080D2494
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x04]
	bl ReleaseObjPalette
	bl func_080D1050
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D24B6
	movs r0, #0xC1
	lsls r0, r0, #0x01
	bl m4aSongNumStop
_080D24B6:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
