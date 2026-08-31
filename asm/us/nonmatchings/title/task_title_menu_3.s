.syntax unified
	.align 2, 0
	.global task_title_menu_3
	.thumb
	.thumb_func
	.type task_title_menu_3, %function
task_title_menu_3: @ 080D6E40
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r0, [r5, #0x00]
	bl ReleaseObjTiles
	ldr r0, [r5, #0x04]
	bl ReleaseObjPalette
	movs r6, #0x00
_080D6E52:
	lsls r4, r6, #0x02
	adds r0, r5, #0x0
	adds r0, #0x08
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl ReleaseObjTiles
	adds r0, r5, #0x0
	adds r0, #0x14
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	adds r6, #0x01
	cmp r6, #0x02
	ble _080D6E52
	adds r0, r5, #0x0
	adds r0, #0x48
	bl TaskPoolDestroy
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
