.syntax unified
	.align 2, 0
	.global func_080034EC
	.thumb
	.thumb_func
	.type func_080034EC, %function
func_080034EC: @ 080034EC
	push {r4, r5, lr}
	movs r3, #0x0F
	ands r1, r3
	ldr r5, _0800350C @ =0x03007528
	ldrh r4, [r5, #0x00]
	movs r2, #0xFF
	ands r2, r4
	ands r3, r0
	lsls r3, r3, #0x08
	orrs r2, r3
	lsls r1, r1, #0x0C
	orrs r2, r1
	strh r2, [r5, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_0800350C: .4byte 0x03007528
	.byte 0x02, 0x49, 0x09, 0x68, 0x02, 0x4A, 0x89, 0x18, 0x08, 0x70, 0x70, 0x47, 0xC8, 0x74, 0x00, 0x03
	.byte 0xAE, 0x2B, 0x00, 0x00
.syntax divided
