.syntax unified
	.align 2, 0
	.global func_080D2F64
	.thumb
	.thumb_func
	.type func_080D2F64, %function
func_080D2F64: @ 080D2F64
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	ldr r6, _080D2FF4 @ =0x0203C530
	movs r4, #0x80
	lsls r4, r4, #0x07
	adds r0, r4, #0x0
	bl func_08000918
	str r0, [r6, #0x00]
	ldr r5, _080D2FF8 @ =0x0203C504
	adds r0, r4, #0x0
	bl func_08000918
	str r0, [r5, #0x00]
	movs r2, #0x00
	ldr r4, _080D2FFC @ =0x00001FFF
	movs r3, #0x00
_080D2F8C:
	ldr r0, [r6, #0x00]
	lsls r1, r2, #0x01
	adds r0, r1, r0
	strh r3, [r0, #0x00]
	ldr r0, [r5, #0x00]
	adds r1, r1, r0
	strh r3, [r1, #0x00]
	adds r2, #0x01
	cmp r2, r4
	bls _080D2F8C
	movs r0, #0x00
	ldr r1, _080D3000 @ =0x0203C4C0
	mov r9, r1
	ldr r3, _080D2FF4 @ =0x0203C530
	mov r8, r3
	ldr r7, _080D3004 @ =0x0203C510
	mov r12, r7
	ldr r1, _080D2FF8 @ =0x0203C504
	mov r10, r1
_080D2FB2:
	movs r4, #0x00
	adds r6, r0, #0x1
	lsls r5, r0, #0x01
_080D2FB8:
	adds r1, r5, r4
	lsls r2, r1, #0x02
	mov r7, r9
	adds r3, r2, r7
	lsls r1, r1, #0x0B
	mov r7, r8
	ldr r0, [r7, #0x00]
	adds r0, r0, r1
	str r0, [r3, #0x00]
	add r2, r12
	mov r3, r10
	ldr r0, [r3, #0x00]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0x01
	bls _080D2FB8
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x03
	bls _080D2FB2
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D2FF4: .4byte 0x0203C530
_080D2FF8: .4byte 0x0203C504
_080D2FFC: .4byte 0x00001FFF
_080D3000: .4byte 0x0203C4C0
_080D3004: .4byte 0x0203C510
.syntax divided
