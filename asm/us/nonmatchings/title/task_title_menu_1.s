.syntax unified
	.align 2, 0
	.global task_title_menu_1
	.thumb
	.thumb_func
	.type task_title_menu_1, %function
task_title_menu_1: @ 080D6A28
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x5C]
	cmp r0, #0x00
	bne _080D6A3A
	ldr r0, [r4, #0x44]
	bl func_080D6944
	b _080D6A54
_080D6A3A:
	cmp r0, #0x03
	bne _080D6A48
	ldr r0, [r4, #0x44]
	movs r1, #0x03
	bl func_080D69AC
	b _080D6A54
_080D6A48:
	cmp r0, #0x04
	bne _080D6A54
	ldr r0, [r4, #0x44]
	movs r1, #0x01
	bl func_080D69AC
_080D6A54:
	adds r0, r4, #0x0
	adds r0, #0x48
	bl TaskPoolUpdate
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
