.syntax unified
	.align 2, 0
	.global func_08019A30
	.thumb
	.thumb_func
	.type func_08019A30, %function
func_08019A30: @ 08019A30
	push {r4, r5, lr}
	ldr r0, _08019A64 @ =0x02039B84
	ldr r5, [r0, #0x00]
	ldr r3, [r5, #0x68]
	ldr r4, [r5, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	adds r0, r3, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08019A6C
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _08019AB4
	ldr r0, _08019A68 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	ldr r3, [r0, #0x7C]
	b _08019AB6
_08019A64: .4byte 0x02039B84
_08019A68: .4byte 0x02039B9C
_08019A6C:
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _08019AB4
	adds r0, r5, #0x0
	adds r0, #0x80
	bl func_08000C8C
	adds r3, r0, #0x0
	cmp r3, #0x00
	beq _08019AC4
	movs r4, #0x81
	negs r4, r4
	asrs r5, r4, #0x1F
_08019A92:
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	ands r0, r4
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	adds r1, r3, #0x0
	adds r1, #0xE2
	movs r0, #0x00
	strh r0, [r1, #0x00]
	adds r0, r3, #0x0
	adds r0, #0xB8
	bl func_08000CD4
	adds r3, r0, #0x0
	cmp r3, #0x00
	bne _08019A92
	b _08019AC4
_08019AB4:
	ldr r3, [r5, #0x7C]
_08019AB6:
	ldr r0, [r3, #0x34]
	ldr r1, [r3, #0x38]
	movs r2, #0x81
	negs r2, r2
	ands r0, r2
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
_08019AC4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
