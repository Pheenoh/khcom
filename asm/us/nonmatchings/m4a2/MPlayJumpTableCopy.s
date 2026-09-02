.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global MPlayJumpTableCopy
	.thumb
	.thumb_func
	.type MPlayJumpTableCopy, %function
MPlayJumpTableCopy:
	mov r12, lr
	movs r1, 0x24
	ldr r2, lt_MPlayJumpTableTemplate
MPlayJumpTableCopy_Loop:
	ldr r3, [r2]
	bl chk_adr_r2
	stm r0!, {r3}
	adds r2, 0x4
	subs r1, 0x1
	bgt MPlayJumpTableCopy_Loop
	bx r12

	.align 2, 0
	.thumb_func
ldrb_r3_r2:
	ldrb r3, [r2]

	.thumb_func
chk_adr_r2:
	push {r0}
	lsrs r0, r2, 25
	bne chk_adr_r2_done
	ldr r0, lt_MPlayJumpTableTemplate
	cmp r2, r0
	blo chk_adr_r2_reject
	lsrs r0, r2, 14
	beq chk_adr_r2_done
chk_adr_r2_reject:
	movs r3, 0
chk_adr_r2_done:
	pop {r0}
	bx lr

	.align 2, 0
lt_MPlayJumpTableTemplate: .word gMPlayJumpTableTemplate
.syntax divided
