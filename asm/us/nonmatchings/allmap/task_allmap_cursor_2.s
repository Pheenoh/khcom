.syntax unified
	.align 2, 0
	.global task_allmap_cursor_2
	.thumb
	.thumb_func
	.type task_allmap_cursor_2, %function
task_allmap_cursor_2: @ 080D3CC0
	push {r4, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	bl func_080D4D1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3D16
	ldr r0, _080D3CE0 @ =0x0203C4E0
	ldr r0, [r0, #0x00]
	cmp r0, #0x03
	beq _080D3CE4
	ldrh r2, [r4, #0x24]
	ldr r0, [r4, #0x28]
	b _080D3CEC
	.byte 0x00, 0x00
_080D3CE0: .4byte 0x0203C4E0
_080D3CE4:
	ldr r0, [r4, #0x3C]
	lsls r0, r0, #0x08
	lsrs r2, r0, #0x10
	ldr r0, [r4, #0x40]
_080D3CEC:
	lsls r0, r0, #0x08
	lsrs r1, r0, #0x10
	lsls r0, r2, #0x10
	ldr r2, _080D3D20 @ =0xFFF10000
	adds r0, r0, r2
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	ldr r2, _080D3D24 @ =0xFFEA0000
	adds r1, r1, r2
	asrs r1, r1, #0x10
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r4, [r4, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r4, #0x31
	str r4, [sp, #0x00C]
	bl DrawSprite
_080D3D16:
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D3D20: .4byte 0xFFF10000
_080D3D24: .4byte 0xFFEA0000
.syntax divided
