.syntax unified
	.align 2, 0
	.global func_0810D3A8
	.thumb
	.thumb_func
	.type func_0810D3A8, %function
func_0810D3A8: @ 0810D3A8
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	movs r5, #0x00
	b _0810D3D2
_0810D3B0:
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
	bne _0810D3CE
	ldr r0, [r4, #0x00]
	bl func_08110984
_0810D3CE:
	adds r5, #0x01
	adds r0, r6, #0x0
_0810D3D2:
	adds r0, #0xC4
	ldr r0, [r0, #0x00]
	cmp r5, r0
	blt _0810D3B0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
