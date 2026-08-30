.syntax unified
	.align 2, 0
	.global mode_status_1
	.thumb
	.thumb_func
	.type mode_status_1, %function
mode_status_1: @ 080D7510
	push {r4, lr}
	bl func_0801CC80
	ldr r4, _080D754C @ =0x02034EE0
	adds r0, r4, #0x0
	bl func_08000EA4
	adds r0, r4, #0x0
	bl func_08000EE0
	ldr r0, _080D7550 @ =0x02034EF4
	ldr r0, [r0, #0x00]
	bl func_08000F48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D7544
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D7544
	ldr r0, _080D7554 @ =0x02034EF8
	ldrb r0, [r0, #0x00]
	bl func_080E052C
_080D7544:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D754C: .4byte 0x02034EE0
_080D7550: .4byte 0x02034EF4
_080D7554: .4byte 0x02034EF8
.syntax divided
