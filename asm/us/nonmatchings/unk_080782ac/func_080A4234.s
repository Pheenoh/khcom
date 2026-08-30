.syntax unified
	.align 2, 0
	.global func_080A4234
	.thumb
	.thumb_func
	.type func_080A4234, %function
func_080A4234: @ 080A4234
	push {r4, r5, lr}
	add sp, #-0x008
	adds r5, r0, #0x0
	lsls r2, r2, #0x10
	lsrs r4, r2, #0x10
	str r1, [sp, #0x000]
	ldr r1, _080A4270 @ =0xFFFF0000
	ldr r0, [sp, #0x004]
	ands r0, r1
	orrs r0, r4
	ldr r1, _080A4274 @ =0x00FFFFFF
	ands r0, r1
	adds r1, #0x01
	orrs r0, r1
	str r0, [sp, #0x004]
	bl func_080A42C8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080A4278
	mov r0, sp
	bl func_080A40EC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080A42A6
	mov r0, sp
	bl func_080A4D7C
	b _080A42A6
_080A4270: .4byte 0xFFFF0000
_080A4274: .4byte 0x00FFFFFF
_080A4278:
	ldr r0, _080A4294 @ =0x09EE8008
	lsls r1, r4, #0x02
	adds r1, r1, r4
	lsls r1, r1, #0x02
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	cmp r0, #0x3E
	bne _080A429C
	ldr r1, _080A4298 @ =0x09EE8E30
	adds r0, r5, #0x0
	mov r2, sp
	bl func_08000E14
	b _080A42A6
_080A4294: .4byte 0x09EE8008
_080A4298: .4byte 0x09EE8E30
_080A429C:
	ldr r1, _080A42B0 @ =0x09EE8E18
	adds r0, r5, #0x0
	mov r2, sp
	bl func_08000E14
_080A42A6:
	add sp, #0x008
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080A42B0: .4byte 0x09EE8E18
	.byte 0x02, 0x48, 0x00, 0x21, 0x01, 0x70, 0x02, 0x48, 0x01, 0x70, 0x70, 0x47, 0xD4, 0xA9, 0x03, 0x02
	.byte 0xD8, 0xA9, 0x03, 0x02
.syntax divided
