.syntax unified
	.align 2, 0
	.global func_080A411C
	.thumb
	.thumb_func
	.type func_080A411C, %function
func_080A411C: @ 080A411C
	push {lr}
	add sp, #-0x008
	adds r3, r0, #0x0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r1, [sp, #0x000]
	ldr r1, _080A4154 @ =0xFFFF0000
	ldr r0, [sp, #0x004]
	ands r0, r1
	orrs r0, r2
	ldr r1, _080A4158 @ =0x00FFFFFF
	ands r0, r1
	str r0, [sp, #0x004]
	ldr r1, _080A415C @ =0x09EE8008
	lsls r0, r2, #0x02
	adds r0, r0, r2
	lsls r0, r0, #0x02
	adds r1, r0, r1
	ldr r0, [r1, #0x00]
	cmp r0, #0x3E
	bne _080A4174
	ldrh r1, [r1, #0x10]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _080A4164
	ldr r1, _080A4160 @ =0x09EE8E48
	b _080A4166
_080A4154: .4byte 0xFFFF0000
_080A4158: .4byte 0x00FFFFFF
_080A415C: .4byte 0x09EE8008
_080A4160: .4byte 0x09EE8E48
_080A4164:
	ldr r1, _080A4170 @ =0x09EE8E30
_080A4166:
	adds r0, r3, #0x0
	mov r2, sp
	bl TaskCreate
	b _080A417E
_080A4170: .4byte 0x09EE8E30
_080A4174:
	ldr r1, _080A4184 @ =0x09EE8E18
	adds r0, r3, #0x0
	mov r2, sp
	bl TaskCreate
_080A417E:
	add sp, #0x008
	pop {r0}
	bx r0
_080A4184: .4byte 0x09EE8E18
.syntax divided
