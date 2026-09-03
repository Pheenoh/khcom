.syntax unified
	.align 2, 0
	.global func_08017728
	.thumb
	.thumb_func
	.type func_08017728, %function
func_08017728: @ 08017728
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r9, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	ldr r0, _08017770 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r4, [r3, #0x68]
	ldr r5, [r3, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	adds r0, r4, #0x0
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08017794
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r1, r4, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _08017778
	ldr r5, [r3, #0x7C]
	ldr r0, _08017774 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	ldr r4, [r0, #0x7C]
	b _08017780
_08017770: .4byte 0x02039B84
_08017774: .4byte 0x02039B9C
_08017778:
	ldr r0, _08017790 @ =0x02039B9C
	ldr r0, [r0, #0x00]
	ldr r5, [r0, #0x7C]
	ldr r4, [r3, #0x7C]
_08017780:
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	mov r2, r9
	mov r3, r8
	bl func_080175BC
	b _080177D6
	.byte 0x00, 0x00
_08017790: .4byte 0x02039B9C
_08017794:
	ldr r5, [r3, #0x7C]
	adds r0, r3, #0x0
	adds r0, #0x80
	bl ListPoolFirst
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _080177D6
	ldr r7, _080177E8 @ =0x00000000
	ldr r6, _080177E4 @ =0x40000000
_080177A8:
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	ands r0, r6
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _080177C8
	ldr r0, [r4, #0x00]
	cmp r0, #0x1F
	beq _080177C8
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	mov r2, r9
	mov r3, r8
	bl func_080175BC
_080177C8:
	adds r0, r4, #0x0
	adds r0, #0xB8
	bl ListPoolNext
	adds r4, r0, #0x0
	cmp r4, #0x00
	bne _080177A8
_080177D6:
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080177E4: .4byte 0x40000000
_080177E8: .4byte 0x00000000
.syntax divided
