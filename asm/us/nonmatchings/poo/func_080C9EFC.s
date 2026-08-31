.syntax unified
	.align 2, 0
	.global func_080C9EFC
	.thumb
	.thumb_func
	.type func_080C9EFC, %function
func_080C9EFC: @ 080C9EFC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	str r0, [sp, #0x000]
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	movs r0, #0x00
	mov r10, r0
	ldr r5, _080C9F64 @ =0x02034DC8
	ldr r1, _080C9F68 @ =0x096FC6F8
	str r1, [sp, #0x004]
	mov r9, r0
	ldr r3, _080C9F6C @ =0x02034DB0
	mov r8, r3
_080C9F1E:
	ldr r6, [sp, #0x004]
	ldr r0, [r6, #0x00]
	str r0, [r5, #0x00]
	ldr r0, _080C9F68 @ =0x096FC6F8
	adds r0, #0x04
	add r0, r9
	ldr r0, [r0, #0x00]
	str r0, [r5, #0x04]
	movs r0, #0x00
	str r0, [r5, #0x08]
	ldr r2, [r6, #0x08]
	ldr r0, _080C9F70 @ =0x09EF4B20
	cmp r2, r0
	beq _080C9F40
	ldr r0, _080C9F74 @ =0x09EF4B08
	cmp r2, r0
	bne _080C9F78
_080C9F40:
	mov r1, r8
	adds r0, r5, #0x0
	ldm r0!, {r3, r6, r7}
	stm r1!, {r3, r6, r7}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	mov r7, r8
	strh r4, [r7, #0x10]
	ldr r0, [sp, #0x000]
	adds r1, r2, #0x0
	mov r2, r8
	bl TaskCreate
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	b _080C9F82
	.byte 0x00, 0x00
_080C9F64: .4byte 0x02034DC8
_080C9F68: .4byte 0x096FC6F8
_080C9F6C: .4byte 0x02034DB0
_080C9F70: .4byte 0x09EF4B20
_080C9F74: .4byte 0x09EF4B08
_080C9F78:
	ldr r0, [sp, #0x000]
	adds r1, r2, #0x0
	adds r2, r5, #0x0
	bl TaskCreate
_080C9F82:
	ldr r0, [sp, #0x004]
	adds r0, #0x0C
	str r0, [sp, #0x004]
	movs r1, #0x0C
	add r9, r1
	movs r3, #0x01
	add r10, r3
	mov r6, r10
	cmp r6, #0x54
	bls _080C9F1E
	adds r0, r4, #0x0
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
