.syntax unified
	.align 2, 0
	.global func_080A4188
	.thumb
	.thumb_func
	.type func_080A4188, %function
func_080A4188: @ 080A4188
	push {lr}
	add sp, #-0x008
	adds r3, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldr r2, _080A41CC @ =0xFFFF0000
	ldr r0, [sp, #0x004]
	ands r0, r2
	orrs r0, r1
	ldr r2, _080A41D0 @ =0x00FFFFFF
	ands r0, r2
	movs r2, #0x80
	lsls r2, r2, #0x12
	orrs r0, r2
	str r0, [sp, #0x004]
	ldr r2, _080A41D4 @ =0x09EE8008
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldrh r1, [r0, #0x10]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080A41DC
	ldr r1, _080A41D8 @ =0x09EE8E48
	adds r0, r3, #0x0
	mov r2, sp
	bl TaskCreate
	b _080A41E6
	.byte 0x00, 0x00
_080A41CC: .4byte 0xFFFF0000
_080A41D0: .4byte 0x00FFFFFF
_080A41D4: .4byte 0x09EE8008
_080A41D8: .4byte 0x09EE8E48
_080A41DC:
	ldr r1, _080A41EC @ =0x09EE8E30
	adds r0, r3, #0x0
	mov r2, sp
	bl TaskCreate
_080A41E6:
	add sp, #0x008
	pop {r0}
	bx r0
_080A41EC: .4byte 0x09EE8E30
.syntax divided
