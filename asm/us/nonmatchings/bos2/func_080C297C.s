.syntax unified
	.align 2, 0
	.global func_080C297C
	.thumb
	.thumb_func
	.type func_080C297C, %function
func_080C297C: @ 080C297C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r1, #0x0
	mov r8, r2
	adds r5, r3, #0x0
	ldr r6, [r0, #0x00]
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r6, r6, r0
	movs r0, #0x00
	movs r1, #0x00
	bl func_080062F4
	movs r0, #0x13
	movs r1, #0x00
	bl func_080062F4
	movs r0, #0x00
	movs r1, #0x14
	movs r2, #0x08
	bl func_08006238
	ldr r0, _080C29E0 @ =0xFFFFEC00
	adds r4, r4, r0
	ldr r0, _080C29E4 @ =0xFFFFF600
	adds r5, r5, r0
	movs r3, #0x80
	lsls r3, r3, #0x01
	adds r0, r4, #0x0
	mov r1, r8
	adds r2, r5, #0x0
	bl func_08018B04
	ldr r0, _080C29E8 @ =0x000002D1
	bl func_0811FE70
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	ldr r2, _080C29EC @ =0x01000000
	ldr r3, _080C29F0 @ =0x00000000
	orrs r0, r2
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C29E0: .4byte 0xFFFFEC00
_080C29E4: .4byte 0xFFFFF600
_080C29E8: .4byte 0x000002D1
_080C29EC: .4byte 0x01000000
_080C29F0: .4byte 0x00000000
.syntax divided
