.syntax unified
	.align 2, 0
	.global func_080D3D40
	.thumb
	.thumb_func
	.type func_080D3D40, %function
func_080D3D40: @ 080D3D40
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x78
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	cmp r1, #0x00
	bge _080D3D58
	movs r0, #0x00
_080D3D58:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	mov r6, r8
	cmp r6, #0x00
	bge _080D3D66
	adds r6, #0x07
_080D3D66:
	asrs r6, r6, #0x03
	lsls r4, r6, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x02
	bl GetBgScreenBase
	adds r7, r0, #0x0
	adds r1, r7, #0x0
	adds r1, #0x1C
	lsls r4, r4, #0x10
	asrs r4, r4, #0x0F
	ldr r5, _080D3DC8 @ =0x0983B7B4
	subs r5, r5, r4
	adds r0, r5, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	adds r1, r7, #0x0
	adds r1, #0x5C
	adds r5, #0x40
	adds r0, r5, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	adds r1, r7, #0x0
	adds r1, #0x9C
	adds r5, #0x40
	adds r0, r5, #0x0
	movs r2, #0x20
	bl RequestDma3Copy
	lsls r6, r6, #0x03
	mov r0, r8
	subs r6, r0, r6
	lsls r6, r6, #0x10
	asrs r0, r6, #0x10
	lsrs r6, r6, #0x1F
	adds r0, r0, r6
	asrs r0, r0, #0x01
	mov r1, r8
	subs r0, r1, r0
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D3DC8: .4byte 0x0983B7B4
.syntax divided
