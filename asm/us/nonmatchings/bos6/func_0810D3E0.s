.syntax unified
	.align 2, 0
	.global func_0810D3E0
	.thumb
	.thumb_func
	.type func_0810D3E0, %function
func_0810D3E0: @ 0810D3E0
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0x0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r5, r2, #0x0
	movs r0, #0x00
	mov r8, r0
	cmp r1, #0x00
	bge _0810D438
	movs r5, #0x00
	adds r0, r6, #0x0
	adds r0, #0xC4
	ldr r1, [r0, #0x00]
	mov r9, r0
	cmp r8, r1
	bge _0810D468
	lsls r7, r2, #0x10
_0810D408:
	lsls r1, r5, #0x02
	movs r2, #0x81
	lsls r2, r2, #0x04
	adds r0, r6, r2
	adds r4, r0, r1
	ldr r0, [r4, #0x00]
	bl func_08110918
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bne _0810D42C
	ldr r0, [r4, #0x00]
	asrs r1, r7, #0x10
	bl func_08110994
	movs r0, #0x01
	mov r8, r0
_0810D42C:
	adds r5, #0x01
	mov r1, r9
	ldr r0, [r1, #0x00]
	cmp r5, r0
	blt _0810D408
	b _0810D468
_0810D438:
	adds r0, r6, #0x0
	adds r0, #0xC4
	ldr r0, [r0, #0x00]
	cmp r1, r0
	bge _0810D468
	lsls r1, r1, #0x02
	movs r2, #0x81
	lsls r2, r2, #0x04
	adds r0, r6, r2
	adds r4, r0, r1
	ldr r0, [r4, #0x00]
	bl func_08110918
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bne _0810D468
	ldr r0, [r4, #0x00]
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	bl func_08110994
	movs r0, #0x01
	mov r8, r0
_0810D468:
	mov r0, r8
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
